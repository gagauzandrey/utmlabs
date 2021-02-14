#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "custom.h"

int main()
{
    std::ifstream read_file;
    read_file.open("cars.csv");
    std::vector<CARS> cars;
    open_file(read_file, cars);

    find_name("BMW", cars);

    std::cout << std::endl;

    changeElement(1, cars, "mercedes", "GLE", "moldova", 2001, 210, 15000);

    for (int i = 0; i < cars.size(); ++i)
    {
        std::cout << i + 1 << ". ";
        cars[i].print();
    }

    std::cout << std::endl;
    deleteElement(2, cars);
    insertElement(4, cars, "Porche", "Cayen", "Italy", 2020, 650, 150000);

    for (int i = 0; i < cars.size(); ++i)
    {
        std::cout << i + 1 << ". ";
        cars[i].print();
    }
    std::cout << std::endl;
    read_file.close();

    std::ofstream write_file;
    write_file.open("cars.csv", std::ios::app);
    writeToFile(write_file, "Toyota", "Land Cruiser", "L200", 2008, 320, 45000);

    std::cout << std::endl;
    for (int i = 0; i < cars.size(); ++i)
    {
        std::cout << i + 1 << ". ";
        cars[i].print();
    }

    write_file.close();
    system("pause");
}
