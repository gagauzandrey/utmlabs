#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int count = 0;
    string str, word;
    char ch;
    ifstream file;
    file.open("lab5v10.txt");
    getline(file, str);
    string inaprop = "#!,.%?/\[&]{}^$'\"@~*|><+=)(;:0123456789";
    for (char c : inaprop)
    {
        str.erase(remove(str.begin(), str.end(), c), str.end());
    }
    cout << "Your string is: \n" << str << endl;
    cout << "Enter your letter: ";
    ch = getchar();
    putchar(ch);
    cout << "\n\n";
    stringstream words(str);
    while (words >> word)
    {
        if (tolower(word[0]) == tolower(ch))
        {
            count++;
            cout << "№" << count << ": " << word << endl;
        }
    }
    cout << "\nThe amount of words starting with the letter \'" << ch << "\' is: " << count << endl;
    system("pause");
    return 0;
}

/* #include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int count = 0;
    string str;
    char ch;
    ifstream file;
    file.open("lab5v10.txt");
    getline(file, str);
    string inaprop = "#!,.%?/\[]{}^$'\"@~*|><+=)(;:";
    for (char c : inaprop) {
        str.erase(remove(str.begin(), str.end(), c), str.end());
    }
    cout << "Your string is: " << str << endl;;
    cout << "Enter your letter: ";
    ch = getchar();
    putchar(ch);
    cout << endl;
    int n = str.length();
    char char_array[n + 1];
    strcpy(char_array, str.c_str());
    char * token = strtok(char_array, " ");
    while (token != NULL) {
        if (tolower(token[0]) == tolower(ch)) {
            cout << token << endl;
            count++;
        }
        token = strtok(NULL, " ");
    }
    cout << "The amount of words starting with the letter " << tolower(ch) << " is: " << count << endl;
    file.close();
    system("pause");
    return 0;
}  */