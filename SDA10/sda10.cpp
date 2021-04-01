#include <iostream>
#include "custom10.h"

int main()
{
    std::vector<Car *> vec;
    readFromFile(vec);
    Node *root = nullptr;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        insert(root, vec[i]);
    }

    int i = 0;
    sort(root, vec, i);
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i]->year << "\t";
    }
    std::cout << "\n";
    int height = maxHeight(root);
    std::cout << "The Height of the BST is: " << height << "\n";
    int count = countNodes(root);
    std::cout << "The BST has " << count << " nodes" << "\n";

    Node *tmp = new Node();
    tmp = searchName(root, "Mercedes");
    std::cout << tmp->data->price << "\n";
    print(root);
    _free(root, vec);
    return 0;
}
