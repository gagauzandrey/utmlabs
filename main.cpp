#include <iostream>
#include <string>
#include <fstream>

struct Car
{
    std::string name{""};
    std::string model{""};
    std::string country{""};
    int year{0};
    int hp{0};
    int price{0};

    Car(const std::string name = "", const std::string model = "", const std::string country = "", const int year = 0, const int hp = 0, const int price = 0) : name(name), model(model), country(country), year(year), hp(hp), price(price){};

    void clear();
};

struct Node
{
    Car *data{nullptr};
    Node *next{nullptr};

    Node() : data(new Car){};
    Node(Car *obj) : data(obj){};
    ~Node();

    void print();
};

struct list
{
    Node *head{nullptr};
    size_t size{0};

    list(){};
    ~list(); // при слиянии двух списков использовать l.clear() для списка, в котором происходило слияние

    void print();
    void push_front(Car *obj);
    void push_back(Car *obj);
    void find_name(const std::string &name);
    void pop(size_t pos);
    void pop_front();
    void pop_back();
    void insertAfter(size_t pos, Car *obj);
    void insertAt(size_t pos, Car *obj);
    void edit(size_t pos, Car *obj);
    void newNode(const std::string &t_name, const std::string &t_model, const std::string &t_country, int t_year, int t_hp, int t_price);
    void sort();
    void getAddress();
    void showSize();
    void calcLen();
    void clear();
};

void splitList(list &l1, list &l2);
void mergeList(list &l1, list &l2);
void readFromFile(list &l);
void writeToFile(list &l);

int main()
{
    list l2, l1;
    Car *obj = new Car("BMW", "M5", "Germany", 2020, 780, 123000);
    Car *obj1 = new Car("Dacia", "Duster", "Romania", 2010, 500, 3000);
    Car *obj2 = new Car("Ferrari", "Berlinetta", "Italy", 2017, 730, 325000);
    Car *obj3 = new Car("Chevrolet", "Camaro", "USA", 2021, 650, 35000);
    Car *obj4 = new Car("Mercedes", "w223", "Germany", 2021, 520, 47000);
    Car *obj5 = new Car("BMW", "1 series", "Germany", 2005, 140, 3000);
    Car *obj6 = new Car("Rolls-Royce", "Phantom", "UK", 2019, 400, 500000);
    Car *obj7 = new Car("Volkswagen", "Passat", "Germany", 2007, 210, 12000);
    Car *obj8 = new Car("Toyota", "Camry", "Japan", 2011, 275, 22000);
    // l1.push_front(obj);
    // l1.push_back(obj1);
    // l1.push_back(obj2);
    // l1.push_back(obj3);
    // l1.showSize();
    // l2.push_front(obj4);
    // l2.push_back(obj5);
    // l2.push_back(obj6);
    // l2.push_back(obj7);
    // l2.push_back(obj8);
    // l2.calcLen();
    // l2.showSize();
    // mergeList(l1, l2);
    // l1.print();
    // splitList(l1, l2);
    // l1.print();
    // l2.print();
    // l1.clear();
    // l2.clear();
    // l1.clear();
    // l1.showSize();
    // l1.calcLen();
    // l1.print();
    // l1.push_back(obj8);
    // l1.insertAfter(2, new Car("mercedes", "gle", "germany", 2002, 340, 5500));
    // l1.print();
    // l1.showSize();

    // l2.showSize();
    // splitList(l1, l2);
    // l1.calcLen();
    // l2.calcLen();
    // l1.print();
    // l1.showSize();
    // std::cout << std::endl;
    // l2.print();
    // l2.showSize();
    list l3;
    readFromFile(l3);
    l3.print();
    // l3.showSize();
    l3.pop_front();
    l3.pop_back();
    l3.print();
    // writeToFile(l3);
    // l3.getAddress();
}

void Node::print()
{
    std::cout << data->name << "\t" << data->model << "\t" << data->country << "\t" << data->year << "\t" << data->hp << "\t" << data->price << std::endl;
}

Node::~Node()
{
    delete data;
}

void list::print()
{
    size_t idx = 1;
    for (Node *tmp = head; tmp; tmp = tmp->next)
    {
        std::cout << idx << ". ";
        tmp->print();
        std::cout << std::endl;
        idx++;
    }
}

void list::push_front(Car *obj)
{
    Node *tmp = head;
    head = new Node(obj);
    head->next = tmp;
    size++;
    return;
}

void list::push_back(Car *obj)
{
    Node *tmp = new Node(obj);
    Node *last = head;
    tmp->next = nullptr;
    if (head == nullptr)
    {
        head = tmp;
        return;
    }
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = tmp;
    size++;
    return;
}

void list::find_name(const std::string &name)
{
    while (head->data->name != name)
    {
        head = head->next;
    }
    std::cout << head->data->name << "\t" << head->data->model << "\t" << head->data->country << "\t" << head->data->year << "\t" << head->data->hp << "\t" << head->data->price << std::endl;
}

void list::edit(size_t pos, Car *obj)
{
    Node *cur = head;
    Node *tmp = new Node(obj);

    if (pos == 0)
    {
        head = tmp;
        head->next = cur;
    }
    else
    {
        int count = 1;
        while (count != pos)
        {
            cur = cur->next;
            count++;
        }
        cur->data = tmp->data;
    }
}

void list::sort()
{
    Node *i, *j;
    i = head;

    for (i = head; i != nullptr; i = i->next)
    {
        for (j = i->next; j != nullptr; j = j->next)
        {
            if (i->data->price > j->data->price)
            {
                std::swap(i->data, j->data);
            }
        }
    }
}

void list::pop(size_t pos)
{
    if (head == nullptr)
    {
        return;
    }

    Node *tmp = head;
    if (pos == 1)
    {
        head = tmp->next;
        delete tmp;
        return;
    }

    for (size_t i = 1; tmp != nullptr && i < pos - 1; ++i)
    {
        tmp = tmp->next;
    }
    if (tmp == nullptr || tmp->next == nullptr)
    {
        return;
    }
    Node *next = tmp->next->next;
    delete tmp->next;
    tmp->next = next;
    size--;
}

void list::pop_front()
{
    if (head)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    size--;
}

void list::pop_back()
{

    if (head == nullptr)
    {
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
    }

    Node *second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (second_last->next);
    second_last->next = nullptr;
    size--;
}

void list::insertAfter(size_t pos, Car *obj)
{
    Node *cur = head;
    Node *tmp = new Node(obj);

    if (pos == 0)
    {
        head = tmp;
        head->next = cur;
    }
    else
    {
        int count = 1;
        while (count != pos)
        {
            cur = cur->next;
            count++;
        }
        tmp->next = cur->next;
        cur->next = tmp;
    }
    size++;
}

void list::insertAt(size_t pos, Car *obj)
{
    Node *cur = head;
    Node *tmp = new Node(obj);

    if (pos == 0)
    {
        head = tmp;
        head->next = cur;
    }
    else
    {
        int count = 1;
        while (count != (pos - 1))
        {
            cur = cur->next;
            count++;
        }
        tmp->next = cur->next;
        cur->next = tmp;
    }
    size++;
}

void list::getAddress()
{
    while (head->next != nullptr)
    {
        head = head->next;
    }
    std::cout << head << std::endl;
}

void list::showSize()
{
    std::cout << size << std::endl;
}

void splitList(list &l1, list &l2)
{
    Node *slow, *fast;
    if (l1.head->next == nullptr)
    {
        return;
    }

    slow = fast = l1.head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    l2.head = slow->next;
    slow->next = nullptr;
    l1.calcLen();
    l2.calcLen();
}

void mergeList(list &l1, list &l2)
{
    Node *tmp = l1.head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = l2.head;
    l1.calcLen();
}

list::~list()
{
    while (head)
    {
        Node *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void list::clear()
{
    while (head)
    {
        Node *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void list::calcLen()
{
    size_t count = 0;
    Node *cur = head;
    while (cur != nullptr)
    {
        cur = cur->next;
        count++;
    }
    size = count;
}

void readFromFile(list &l)
{
    std::ifstream file;
    std::string line;
    file.open("cars.csv");
    if (!file.is_open())
    {
        return;
    }

    l.size = 1;
    size_t p = 0, start = 0;
    const std::string delim = "\",\n";
    std::string str;
    std::string t_name = "";
    std::string t_model = "";
    std::string t_country = "";
    int t_year = 0, t_hp = 0, t_price = 0;
    while (getline(file, line, '\n'))
    {
        if (!line.find("Name"))
            continue;
        size_t len = line.length();
        start = line.find_first_not_of(delim, p);
        p = line.find_first_of(delim, start);
        while (p != std::string::npos)
        {
            str = line.substr(start, p - start);
            if (t_name == "")
            {
                t_name = str;
            }
            else if (t_model == "")
            {
                t_model = str;
            }
            else if (t_country == "")
            {
                t_country = str;
            }
            else if (t_year == 0)
            {
                t_year = std::stoi(str);
            }
            else if (t_hp == 0)
            {
                t_hp = std::stoi(str);
            }
            start = line.find_first_not_of(delim, p);
            p = line.find_first_of(delim, start);
        }
        if (len > start) //rest
        {
            str = line.substr(start, len - start);
            if (t_price == 0)
            {
                t_price = std::stoi(str);
            }
        }
        p = 0, start = 0;
        l.newNode(t_name, t_model, t_country, t_year, t_hp, t_price);
        t_name = "";
        t_model = "";
        t_country = "";
        t_year = 0, t_hp = 0, t_price = 0;
    }
    file.close();
}

void list::newNode(const std::string &t_name, const std::string &t_model, const std::string &t_country, int t_year, int t_hp, int t_price)
{
    Node *tmp = new Node();
    tmp->data->name = t_name;
    tmp->data->model = t_model;
    tmp->data->country = t_country;
    tmp->data->year = t_year;
    tmp->data->hp = t_hp;
    tmp->data->price = t_price;
    tmp->next = nullptr;
    Node *last = head;
    if (head == nullptr)
    {
        head = tmp;
        return;
    }

    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = tmp;
    size++;
}

void writeToFile(list &l)
{
    std::ofstream file;
    file.open("cars.csv", std::ios::app);
    if (!file.is_open())
    {
        return;
    }
    std::string str;
    std::string t_name = "";
    std::string t_model = "";
    std::string t_country = "";
    int t_year = 0, t_hp = 0, t_price = 0;

    if (l.head == nullptr)
    {
        return;
    }
    Node *cur = l.head;
    while (cur->next != nullptr)
    {
        t_name = cur->data->name;
        t_model = cur->data->model;
        t_country = cur->data->country;
        t_year = cur->data->year;
        t_hp = cur->data->hp;
        t_price = cur->data->price;
        file << t_name << "," << t_model << "," << t_country << "," << t_year << "," << t_hp << "," << t_price << std::endl;
        cur = cur->next;
    }
    file.close();
}

void Car::clear()
{
    name = "";
    model = "";
    country = "";
    year = 0;
    hp = 0;
    price = 0;
}