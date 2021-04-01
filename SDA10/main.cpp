#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//DONE
// 1. создание узлов дерева
//DONE
// 2. ввод информации в узлы
//DONE
// 3. вывод узлов
//DONE
// 4. поиск узла
//DONE
// 5. определение количества узлов и высоты дерева
//DONE
// 6. освобождение памяти

struct Car
{
    std::string name{""};
    std::string model{""};
    std::string country{""};
    int year{0};
    int hp{0};
    int price{0};
};

struct Node
{
    Car *data{nullptr};
    Node *left{nullptr};
    Node *right{nullptr};

    Node() : data(new Car){};
    Node(Car *obj) : data(obj){};
};

void insert(Node *&root, Car *obj);
void print(Node *root);
int maxHeight(Node *root);
int countNodes(Node *root);
void sort(Node *root, std::vector<Car *> &vec, int &i);
Node *searchName(Node *root, const std::string &str);
void free(Node * root);
void _free(Node *& root, std::vector<Car *> & vec);
void readFromFile(std::vector<Car *> &vec);
void clearVec(std::vector<Car *> &vec);

int main()
{
    std::vector<Car *> vec;
    readFromFile(vec);
    int i = 0;
    Node *root = nullptr;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        insert(root, vec[i]);
    }

    sort(root, vec, i);
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i]->year << "\t";
    }
    std::cout << "\n";
    int height = maxHeight(root);
    std::cout << height << "\n";
    int count = countNodes(root);
    std::cout << count << "\n";

    Node *tmp = new Node();
    tmp = searchName(root, "Lada");
    std::cout << tmp->data->price << "\n";
    print(root);
    _free(root, vec);
    return 0;
}

void insert(Node *&root, Car *obj)
{
    if (!root)
    {
        root = new Node(obj);
        return;
    }

    if (obj->year > root->data->year)
    {
        insert(root->right, obj);
    }
    else
    {
        insert(root->left, obj);
    }
}

void print(Node *root)
{
    if (!root)
    {
        return;
    }
    print(root->left);
    std::cout << root->data->name << " " << root->data->model << " " << root->data->country << " " << root->data->year << " " << root->data->hp << " " << root->data->price << "\n";
    print(root->right);
}

void sort(Node *root, std::vector<Car *> &vec, int &i)
{
    if (!root)
    {
        return;
    }
    sort(root->left, vec, i);
    vec[i++] = root->data;
    sort(root->right, vec, i);
}

int maxHeight(Node *root)
{
    if (!root)
        return 0;
    else
    {
        int lHeight = maxHeight(root->left);
        int rHeight = maxHeight(root->right);

        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

int countNodes(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void readFromFile(std::vector<Car *> &vec)
{
    std::ifstream file;
    std::string line;
    file.open("D:/UTM/C++ Primer/SDA10/cars.csv");
    if (!file.is_open())
    {
        std::cout << "Couldn't open the file!"
                  << "\n";
        return;
    }

    size_t p = 0, start = 0;
    const std::string delim = "\",\n";
    std::string str;
    while (getline(file, line, '\n'))
    {

        Car *tmp = new Car();
        if (!line.find("Name"))
            continue;
        size_t len = line.length();
        start = line.find_first_not_of(delim, p);
        p = line.find_first_of(delim, start);
        while (p != std::string::npos)
        {
            str = line.substr(start, p - start);
            if (tmp->name == "")
            {
                tmp->name = str;
            }
            else if (tmp->model == "")
            {
                tmp->model = str;
            }
            else if (tmp->country == "")
            {
                tmp->country = str;
            }
            else if (tmp->year == 0)
            {
                tmp->year = std::stoi(str);
            }
            else if (tmp->hp == 0)
            {
                tmp->hp = std::stoi(str);
            }
            start = line.find_first_not_of(delim, p);
            p = line.find_first_of(delim, start);
        }
        if (len > start)
        {
            str = line.substr(start, len - start);
            if (tmp->price == 0)
            {
                tmp->price = std::stoi(str);
            }
        }
        vec.push_back(tmp);
        p = 0, start = 0;
    }
    file.close();
}

Node *searchName(Node *root, const std::string &str)
{
    if (!root)
        return nullptr;

    if (str < root->data->name)
    {
        return searchName(root->left, str);
    }
    else if (str > root->data->name)
    {
        return searchName(root->right, str);
    }
    return root;
}

void free(Node *root)
{
    if (!root)
    {
        return;
    }
    free(root->left);
    free(root->right);
    delete root->data;
    delete root;
}

void _free(Node *& root, std::vector<Car *> & vec) {
    free(root);
    root = nullptr;
    vec.clear();
}
