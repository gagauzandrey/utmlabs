#include <iostream>
#include <vector>
using namespace std;

void initAdjMat(vector<vector<int>> &adjMat, size_t V);
void fillAdjMat(vector<vector<int>> &adjMat, size_t V);
void printAdjMat(vector<vector<int>> adjMat, size_t V);
void adjMatToList(vector<vector<int>> adjMat, vector<int> adjList[]);
void listToAdjMat(vector<int> adjList[], vector<vector<int>> &adjMat, size_t V);
void adjMatToIncMat(vector<vector<int>> adjMat, vector<vector<int>> &incMat, size_t V);
void initIncMat(vector<vector<int>> &incMat, size_t V, size_t E);
void fillIncMat(vector<vector<int>> &incMat, size_t V, size_t E);
void printIncMat(vector<vector<int>> incMat, size_t V, size_t E);
void incMatToList(vector<vector<int>> incMat, vector<int> adjList[], size_t V, size_t E);
void listToIncMat(vector<int> adjList[], vector<vector<int>> &incMat, size_t V);
void incMatToAdjMat(vector<vector<int>> incMat, vector<vector<int>> &adjMat, size_t V, size_t E);
void fillAdjList(vector<int> adjList[], size_t E);
void addEdge(vector<int> adjList[], int start_v, int end_v);
void printAdjList(vector<int> adjList[], size_t V);
void printStartMenu();
void printInputMenu();
void printOutputMenu();

int main()
{
    int V = 4, E = 6;
    vector<int> adjList[V];
    vector<vector<int>> adjMat;
    vector<vector<int>> incMat;
    short int choice = 0;

    printStartMenu();
    while (choice < 1 || choice > 3)
    {
        cout << "Choose between these three options: ";
        cin >> choice;
    }

    cout << endl;
    bool isGraph = false;
    if (choice == 1)
    {
        isGraph = true;
        printInputMenu();
        cout << "Choose between these three options: ";
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << "Enter valid option: ";
            cin >> choice;
        }

        if (choice == 1)
        {
            fillAdjMat(adjMat, V);
            adjMatToList(adjMat, adjList);
            initIncMat(incMat, V, E);
            adjMatToIncMat(adjMat, incMat, V);
        }
        else if (choice == 2)
        {
            fillAdjList(adjList, E);
            initAdjMat(adjMat, V);
            listToAdjMat(adjList, adjMat, V);
            initIncMat(incMat, V, E);
            listToIncMat(adjList, incMat, V);
        }
        else if (choice == 3)
        {
            fillIncMat(incMat, V, E);
            incMatToList(incMat, adjList, V, E);
            initAdjMat(adjMat, V);
            incMatToAdjMat(incMat, adjMat, V, E);
        }

        printStartMenu();
        cout << "Choose what do want to do next. You can either display your graph or exit the program. ";
        cout << "Choose between these two options (2 or 3): ";
        cin >> choice;
        /* while (choice != 2 || choice != 3)
        {
            cout << "Enter valid option: ";
            cin >> choice;
        } */

        if (choice == 2)
        {
            /* printOutputMenu();
            cout << "Choose between these three options: ";
            cin >> choice;
            while (choice < 1 || choice > 3)
            {
                cout << "Enter valid option: ";
                cin >> choice;
            }

            if (choice == 1)
            {
                printAdjMat(adjMat, V);
            }
            else if (choice == 2)
            {
                printAdjList(adjList, E);
            }
            else if (choice == 3)
            {
                printIncMat(incMat, V, E);
            } */
            do
            {
                printOutputMenu();
                cout << "Choose between these three options: ";
                cin >> choice;
                if (choice == 1)
                {
                    printAdjMat(adjMat, V);
                }
                else if (choice == 2)
                {
                    printAdjList(adjList, V);
                }
                else if (choice == 3)
                {
                    printIncMat(incMat, V, E);
                }
            } while (choice == 1 || choice == 2 || choice == 3);
        }
        else if (choice == 3)
        {
            return 1;
        }
    }
    else if (choice == 2)
    {
        if (isGraph)
        {
            // printOutputMenu();
            /* cout << "Choose between these three options: ";
            cin >> choice; */
            /* while (choice < 1 || choice > 3)
            {
                cout << "Enter valid option: ";
                cin >> choice;
            } */

            do
            {
                printOutputMenu();
                cout << "Choose between these three options: ";
                cin >> choice;
                if (choice == 1)
                {
                    printAdjMat(adjMat, V);
                }
                else if (choice == 2)
                {
                    printAdjList(adjList, V);
                }
                else if (choice == 3)
                {
                    printIncMat(incMat, V, E);
                }
            } while (choice == 1 || choice == 2 || choice == 3);
        }
        else
        {
            cout << "You need to enter your graph before you can display it!" << endl;
            cout << "You can either enter your graph or exit the program. Choose 1 or 3: ";
            cin >> choice;
            /* while (choice != 1 || choice != 3)
            {
                cout << "Press 1 or 3: ";
                cin >> choice;
            } */
            if (choice == 1)
            {
                printInputMenu();
                cout << "Choose between these three options: ";
                cin >> choice;
                while (choice < 1 || choice > 3)
                {
                    cout << "Enter valid option: ";
                    cin >> choice;
                }

                if (choice == 1)
                {
                    fillAdjMat(adjMat, V);
                    adjMatToList(adjMat, adjList);
                    initIncMat(incMat, V, E);
                    adjMatToIncMat(adjMat, incMat, V);
                }
                else if (choice == 2)
                {
                    fillAdjList(adjList, E);
                    initAdjMat(adjMat, V);
                    listToAdjMat(adjList, adjMat, V);
                    initIncMat(incMat, V, E);
                    listToIncMat(adjList, incMat, V);
                }
                else if (choice == 3)
                {
                    fillIncMat(incMat, V, E);
                    incMatToList(incMat, adjList, V, E);
                    initAdjMat(adjMat, V);
                    incMatToAdjMat(incMat, adjMat, V, E);
                }

                printStartMenu();
                cout << "Choose what do want to do next. You can either display your graph or exit the program" << endl;
                cout << "Choose between these two options (2 or 3): ";
                cin >> choice;
                while (choice < 2 || choice > 3)
                {
                    cout << "Enter valid option: ";
                    cin >> choice;
                }

                if (choice == 2)
                {
                    do
                    {
                        printOutputMenu();
                        cout << "Choose between these three options: ";
                        cin >> choice;
                        if (choice == 1)
                        {
                            printAdjMat(adjMat, V);
                        }
                        else if (choice == 2)
                        {
                            printAdjList(adjList, V);
                        }
                        else if (choice == 3)
                        {
                            printIncMat(incMat, V, E);
                        }
                    } while (choice == 1 || choice == 2 || choice == 3);
                }
                else if (choice == 3)
                {
                    return 1;
                }
            }
            else if (choice == 3)
            {
                return 1;
            }
        }
    }
    else if (choice == 3)
    {
        return 1;
    }
}

void initAdjMat(vector<vector<int>> &adjMat, size_t V)
{
    for (int i = 0; i < V; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < V; ++j)
        {
            tmp.push_back(0);
        }
        adjMat.push_back(tmp);
    }
}

void fillAdjMat(vector<vector<int>> &adjMat, size_t V)
{
    int num = 0;
    for (int i = 0; i < V; ++i)
    {
        cout << "Enter row " << i << ": ";
        vector<int> tmp;
        for (int j = 0; j < V; ++j)
        {
            cin >> num;
            tmp.push_back(num);
        }
        adjMat.push_back(tmp);
    }
}

void printAdjMat(vector<vector<int>> adjMat, size_t V)
{
    cout << '\t';
    for (int k = 0; k < V; ++k)
    {
        cout << "x" << k + 1 << '\t';
    }
    cout << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "x" << i + 1 << '\t';
        for (int j = 0; j < V; j++)
        {
            cout << " " << adjMat[i][j] << '\t';
        }
        cout << endl;
    }
}

void adjMatToList(vector<vector<int>> adjMat, vector<int> adjList[]) // adj mat to list
{
    for (int i = 0; i < adjMat.size(); ++i)
    {
        for (int j = 0; j < adjMat[i].size(); ++j)
        {
            if (adjMat[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
}

void listToAdjMat(vector<int> adjList[], vector<vector<int>> &adjMat, size_t V)
{
    for (int i = 0; i < V; ++i)
    {
        int k;
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            k = adjList[i][j];
            adjMat[i][k] = 1;
        }
    }
}

void adjMatToIncMat(vector<vector<int>> adjMat, vector<vector<int>> &incMat, size_t V)
{
    vector<vector<int>> edge_mat;
    for (int i = 0; i < V; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < V; ++j)
        {
            if (adjMat[i][j] == 1)
            {
                tmp.push_back(i);
                tmp.push_back(j);
                edge_mat.push_back(tmp);
                tmp.clear();
            }
        }
    }

    int start_v, end_v;
    for (int i = 0; i < edge_mat.size(); ++i)
    {
        start_v = edge_mat[i][0];
        end_v = edge_mat[i][1];
        incMat[i][start_v] = -1;
        incMat[i][end_v] = 1;
    }
}

void initIncMat(vector<vector<int>> &incMat, size_t V, size_t E)
{
    for (int i = 0; i < E; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < V; ++j)
        {
            tmp.push_back(0);
        }
        incMat.push_back(tmp);
    }
}

void fillIncMat(vector<vector<int>> &incMat, size_t V, size_t E)
{
    int num = 0;
    for (int i = 0; i < E; ++i)
    {
        cout << "Enter row " << i << ": ";
        vector<int> tmp;
        for (int j = 0; j < V; ++j)
        {
            cin >> num;
            tmp.push_back(num);
        }
        incMat.push_back(tmp);
    }
}

void printIncMat(vector<vector<int>> incMat, size_t V, size_t E)
{
    cout << '\t';
    for (int k = 0; k < V; ++k)
    {
        cout << "x" << k + 1 << '\t';
    }
    cout << endl;
    for (int i = 0; i < incMat.size(); i++)
    {
        cout << "e" << i + 1 << '\t';
        for (int j = 0; j < incMat[i].size(); j++)
        {
            cout << " " << incMat[i][j] << '\t';
        }
        cout << endl;
    }
}

void incMatToList(vector<vector<int>> incMat, vector<int> adjList[], size_t V, size_t E)
{
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            if (incMat[j][i] == -1)
            {
                for (int k = 0; k < V; ++k)
                {
                    if (incMat[j][k] == 1)
                    {
                        adjList[i].push_back(k);
                    }
                }
            }
        }
    }
}

void incMatToAdjMat(vector<vector<int>> incMat, vector<vector<int>> &adjMat, size_t V, size_t E)
{
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            if (incMat[j][i] == -1)
            {
                for (int k = 0; k < V; ++k)
                {
                    if (incMat[j][k] == 1)
                    {
                        adjMat[i][k] = 1;
                    }
                }
            }
        }
    }
}

void listToIncMat(vector<int> adjList[], vector<vector<int>> &incMat, size_t V)
{
    vector<vector<int>> edge_mat;
    for (int i = 0; i < V; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            tmp.push_back(i);
            tmp.push_back(adjList[i][j]);
            edge_mat.push_back(tmp);
            tmp.clear();
        }
    }

    int start_v, end_v;
    for (int i = 0; i < edge_mat.size(); ++i)
    {
        start_v = edge_mat[i][0];
        end_v = edge_mat[i][1];
        incMat[i][start_v] = -1;
        incMat[i][end_v] = 1;
    }
}

void fillAdjList(vector<int> adjList[], size_t E)
{
    int start_v = 0, end_v = 0;
    cout << "All the input is needed to be done with whitespaces!!! You have " << E << " edges." << endl;
    for (int i = 0; i < E; ++i)
    {
        cout << "Enter edge " << i + 1 << ": ";
        cin >> start_v >> end_v;
        addEdge(adjList, start_v - 1, end_v - 1);
    }
}

void addEdge(vector<int> adjList[], int start_v, int end_v)
{
    adjList[start_v].push_back(end_v);
}

void printAdjList(vector<int> adjList[], size_t V)
{
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i + 1;
        for (auto x : adjList[i])
        {
            cout << " -> " << x + 1;
        }
        cout << endl;
    }
}

void printStartMenu()
{
    cout << '\n'
         << "     "
         << "Start Menu" << endl;
    cout << "--------------------" << endl;
    cout << "| 1. Enter Graph   |" << endl;
    cout << "| 2. Display Graph |" << endl;
    cout << "| 3. Exit          |" << endl;
    cout << "--------------------" << endl;
}

void printInputMenu()
{
    cout << '\n'
         << '\t' << "Input Menu" << endl;
    cout << "-----------------------------" << endl;
    cout << "| 1. Enter Adjacency Matrix |" << endl;
    cout << "| 2. Enter Adjacency List   |" << endl;
    cout << "| 3. Enter Incidence Matrix |" << endl;
    cout << "-----------------------------" << endl;
}

void printOutputMenu()
{
    cout << '\n'
         << '\t' << "Output Menu" << endl;
    cout << "-----------------------------" << endl;
    cout << "| 1. Display Adjacency Matrix |" << endl;
    cout << "| 2. Display Adjacency List   |" << endl;
    cout << "| 3. Display Incidence Matrix |" << endl;
    cout << "-----------------------------" << endl;
}
