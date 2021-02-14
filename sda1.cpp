#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>

struct CARS
{
    std::string name{""};
    std::string model{""};
    std::string country{""};
    int year{0};
    int hp{0};
    int price{0};

    void print();
};

void CARS::print()
{
    std::cout << this->name << " " << this->model << " " << this->country << " " << this->year << " " << this->hp << " " << this->price << std::endl;
}

void open_file(std::ifstream &file, std::vector<CARS> &cars);
void find_name(std::string str, std::vector<CARS> cars);
void find_model(std::string str, std::vector<CARS> cars);
void find_country(std::string str, std::vector<CARS> cars);
void find_year(int year, std::vector<CARS> cars);
void find_hp(int hp, std::vector<CARS> cars);
void find_price(int price, std::vector<CARS> cars);
void sortMenu(std::vector<CARS> &cars);
bool cmpByNameUp(const CARS &a, const CARS &b);
bool cmpByNameDown(const CARS &a, const CARS &b);
bool cmpByModelUp(const CARS &a, const CARS &b);
bool cmpByModelDown(const CARS &a, const CARS &b);
bool cmpByCountryUp(const CARS &a, const CARS &b);
bool cmpByCountryDown(const CARS &a, const CARS &b);
bool cmpByYearUp(const CARS &a, const CARS &b);
bool cmpByYearDown(const CARS &a, const CARS &b);
bool cmpByHpUp(const CARS &a, const CARS &b);
bool cmpByHpDown(const CARS &a, const CARS &b);
bool cmpByPriceUp(const CARS &a, const CARS &b);
bool cmpByPriceDown(const CARS &a, const CARS &b);
void changeElement(size_t pos, std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price);
void pushElement(std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price);
void deleteElement(size_t pos, std::vector<CARS> &cars);
void insertElement(size_t pos, std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price);

int main()
{
    std::ifstream file;
    file.open("cars.csv");
    std::vector<CARS> cars;
    open_file(file, cars);

    /* for (int i = 0; i < cars.size(); ++i) {121``1
        cars[i].print();
    } */

    // find_name("BMW", cars);
    // std::sort(cars.begin(), cars.end(), cmpByPriceUp);

    std::cout << std::endl;

    // changeElement(-1, cars, "mercedes", "GLE", "moldova", 2001, 210, 15000);

    for (int i = 0; i < cars.size(); ++i)
    {
        std::cout << i + 1 << ". ";
        cars[i].print();
    }

    std::cout << std::endl;
    // pushElement(cars, "Porche", "Cayen", "Italy", 2020, 650, 150000);
    deleteElement(2, cars);
    insertElement(4, cars, "Porche", "Cayen", "Italy", 2020, 650, 150000);

    for (int i = 0; i < cars.size(); ++i)
    {
        std::cout << i + 1 << ". ";
        cars[i].print();
    }

    system("pause");
}

void open_file(std::ifstream &file, std::vector<CARS> &cars)
{
    if (file.is_open())
    {
        size_t i = 0;
        size_t pos = 0;
        std::string token;
        std::string buf;
        std::string delim = ",";
        std::vector<std::vector<std::string>> out_stream;
        std::string skip = "Name";
        while (getline(file, buf, '\n'))
        {
            if(!(buf.find(skip))) continue;
            std::vector<std::string> tmp;
            while ((pos = buf.find(delim)) != std::string::npos)
            {
                token = buf.substr(0, pos);
                tmp.push_back(token);
                buf.erase(0, pos + delim.length());
            }
            CARS tmp_car;
            out_stream.push_back(tmp);
            tmp.clear();
            tmp_car.name = out_stream[i][0];
            tmp_car.model = out_stream[i][1];
            tmp_car.country = out_stream[i][2];
            tmp_car.year = atoi(out_stream[i][3].c_str());
            tmp_car.hp = atoi(out_stream[i][4].c_str());
            tmp_car.price = atoi(out_stream[i][5].c_str());
            cars.push_back(tmp_car);
            i++;
        }
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

void find_name(std::string str, std::vector<CARS> cars)
{
    for (int i = 0; i < cars.size(); ++i)
    {
        if (str == cars[i].name)
        {
            cars[i].print();
        }
    }
};

void find_model(std::string str, std::vector<CARS> cars)
{
    for (int i = 0; i < cars.size(); ++i)
    {
        if (str == cars[i].model)
        {
            cars[i].print();
        }
    }
};

void find_country(std::string str, std::vector<CARS> cars)
{
    for (int i = 0; i < cars.size(); ++i)
    {
        if (str == cars[i].country)
        {
            cars[i].print();
        }
    }
};

void find_year(int year, std::vector<CARS> cars)
{
    for (int i = 0; i < cars.size(); ++i)
    {
        if (year == cars[i].year)
        {
            cars[i].print();
        }
    }
};

void find_hp(int hp, std::vector<CARS> cars)
{
    for (int i = 0; i < cars.size(); ++i)
    {
        if (hp == cars[i].hp)
        {
            cars[i].print();
        }
    }
};

void find_price(int price, std::vector<CARS> cars)
{
    for (int i = 0; i < cars.size(); ++i)
    {
        if (price == cars[i].price)
        {
            cars[i].print();
        }
    }
};

bool cmpByNameUp(const CARS &a, const CARS &b)
{
    return a.name[0] < b.name[0];
}

bool cmpByNameDown(const CARS &a, const CARS &b)
{
    return a.name[0] > b.name[0];
}

bool cmpByModelUp(const CARS &a, const CARS &b)
{
    return a.model[0] < b.model[0];
}

bool cmpByModelDown(const CARS &a, const CARS &b)
{
    return a.model[0] > b.model[0];
}

bool cmpByCountryUp(const CARS &a, const CARS &b)
{
    return a.country[0] < b.country[0];
}

bool cmpByCountryDown(const CARS &a, const CARS &b)
{
    return a.country[0] > b.country[0];
}

bool cmpByYearUp(const CARS &a, const CARS &b)
{
    return a.year < b.year;
}

bool cmpByYearDown(const CARS &a, const CARS &b)
{
    return a.year > b.year;
}

bool cmpByHpUp(const CARS &a, const CARS &b)
{
    return a.hp < b.hp;
}

bool cmpByHpDown(const CARS &a, const CARS &b)
{
    return a.hp > b.hp;
}

bool cmpByPriceUp(const CARS &a, const CARS &b)
{
    return a.price < b.price;
}

bool cmpByPriceDown(const CARS &a, const CARS &b)
{
    return a.price > b.price;
}

void sortMenu(std::vector<CARS> &cars)
{
    std::cout << "1. Sort by Name Down" << std::endl;
    std::cout << "2. Sort by Name Up" << std::endl;
    std::cout << "3. Sort by Model Down" << std::endl;
    std::cout << "4. Sort by Model Up" << std::endl;
    std::cout << "5. Sort by Country Down" << std::endl;
    std::cout << "6. Sort by Country Up" << std::endl;
    std::cout << "7. Sort by Year Down" << std::endl;
    std::cout << "8. Sort by Year Up" << std::endl;
    std::cout << "9. Sort by Hp Down" << std::endl;
    std::cout << "10. Sort by Hp Up" << std::endl;
    std::cout << "11. Sort by Price Down" << std::endl;
    std::cout << "12. Sort by Price Up" << std::endl;

    size_t choice = 0;
    std::cout << "How do you want to sort your list? ";
    std::cin >> choice;
    std::cout << std::endl;
    if (choice == 1)
    {
        std::sort(cars.begin(), cars.end(), cmpByNameDown);
    }
    if (choice == 2)
    {
        std::sort(cars.begin(), cars.end(), cmpByNameUp);
    }
    if (choice == 3)
    {
        std::sort(cars.begin(), cars.end(), cmpByModelDown);
    }
    if (choice == 4)
    {
        std::sort(cars.begin(), cars.end(), cmpByModelUp);
    }
    if (choice == 5)
    {
        std::sort(cars.begin(), cars.end(), cmpByCountryDown);
    }
    if (choice == 6)
    {
        std::sort(cars.begin(), cars.end(), cmpByCountryUp);
    }
    if (choice == 7)
    {
        std::sort(cars.begin(), cars.end(), cmpByYearDown);
    }
    if (choice == 8)
    {
        std::sort(cars.begin(), cars.end(), cmpByYearUp);
    }
    if (choice == 9)
    {
        std::sort(cars.begin(), cars.end(), cmpByHpDown);
    }
    if (choice == 10)
    {
        std::sort(cars.begin(), cars.end(), cmpByHpUp);
    }
    if (choice == 11)
    {
        std::sort(cars.begin(), cars.end(), cmpByPriceDown);
    }
    if (choice == 12)
    {
        std::sort(cars.begin(), cars.end(), cmpByPriceUp);
    }
}

void changeElement(size_t pos, std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price)
{
    size_t len = cars.size();
    if (pos > len || pos < 0)
    {
        std::cout << "Incorrect index" << std::endl;
    }
    else
    {
        cars[pos - 1].name = name;
        cars[pos - 1].model = model;
        cars[pos - 1].country = country;
        cars[pos - 1].year = year;
        cars[pos - 1].hp = hp;
        cars[pos - 1].price = price;
    }
}

void pushElement(std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price) {
    CARS tmp;
    tmp.name = name;
    tmp.model = model;
    tmp.country = country;
    tmp.year = year;
    tmp.hp = hp;
    tmp.price = price;
    cars.push_back(tmp);
}

void deleteElement(size_t pos, std::vector<CARS> &cars) {
    size_t len = cars.size();
    if (pos > len || pos < 0)
    {
        std::cout << "Incorrect index" << std::endl;
    }
    else
    {
        cars.erase(cars.begin() + (pos - 1));
    }
}

void insertElement(size_t pos, std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price) {
    size_t len = cars.size();
    if (pos > len || pos < 0)
    {
        std::cout << "Incorrect index" << std::endl;
    }
    else
    {   
        CARS tmp;
        tmp.name = name;
        tmp.model = model;
        tmp.country = country;
        tmp.year = year;
        tmp.hp = hp;
        tmp.price = price;
        cars.insert(cars.begin() + (pos - 1), tmp);
    }
}