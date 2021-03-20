#include <iostream>
#include <list>
#include <queue>
#include <stack>

enum status
{
    UNKNOWN,
    DISCOVERED,
    VISITED,
};

struct Graph
{
    int numVertices;
    status *visited;
    std::list<int> *adjLists;
    Graph(int vertices);
    void addEdge(int src, int dst);
    void sortAdj();
    void printAdjLists();
    void DFS(int strt);
    void BFS(int strt);
};

void printMenu();

int main()
{
    int V;
    std::cout << "Enter the number of your graph's vertices: ";
    std::cin >> V;
    Graph g(V);

    int choice = 0;
    bool isGraph = false;
    while (choice != -1)
    {
        printMenu();
        std::cout << "Make your choice (press -1 to exit): ";
        std::cin >> choice;

        int strtV;

        if (choice == 1)
        {
            if (!isGraph)
            {
                isGraph = true;
                int dst;
                std::cout << "Enter -1 to end entering an adjacency list!"
                          << "\n";
                for (int i = 0; i < V; ++i)
                {
                    dst = 0;
                    while (dst != -1)
                    {
                        std::cout << "Vertex " << i << ": ";
                        std::cin >> dst;
                        g.addEdge(i, dst);
                    }
                }
                g.sortAdj();

                std::cout << std::endl;
                std::cout << "Your graph: " << std::endl;
                g.printAdjLists();
            }
            else
            {
                std::cout << "You have already entered the graph. Do you want to enter another one? Press 1 to do so or press -1 to exit: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    g.~Graph();
                    std::cout << "Enter the number of your graph's vertices: ";
                    std::cin >> V;
                    Graph g(V);
                    isGraph = false;

                    int dst;
                    std::cout << "Enter -1 to end entering an adjacency list!"
                              << "\n";
                    for (int i = 0; i < V; ++i)
                    {
                        dst = 0;
                        while (dst != -1)
                        {
                            std::cout << "Vertex " << i << ": ";
                            std::cin >> dst;
                            g.addEdge(i, dst);
                        }
                    }
                    g.sortAdj();

                    std::cout << std::endl;
                    std::cout << "Your graph: " << std::endl;
                    g.printAdjLists();
                }
                else if (choice == -1)
                {
                    return 0;
                }
            }
        }
        else if (choice == 2)
        {
            if (isGraph)
            {
                std::cout << "Enter start vertex for DFS: ";
                std::cin >> strtV;
                while (strtV < 0)
                {
                    std::cout << "Start vertex must be >= 0: ";
                    std::cin >> strtV;
                }
                g.DFS(strtV);
                std::cout << std::endl;
            }
            else
            {
                std::cout << "You haven't entered the graph yet. Press 1 to do it or press -1 to exit the program: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    isGraph = true;
                    int dst;
                    std::cout << "Enter -1 to end entering an adjacency list!"
                              << "\n";
                    for (int i = 0; i < V; ++i)
                    {
                        dst = 0;
                        while (dst != -1)
                        {
                            std::cout << "Vertex " << i << ": ";
                            std::cin >> dst;
                            g.addEdge(i, dst);
                        }
                    }
                    g.sortAdj();

                    std::cout << std::endl;
                    std::cout << "Your graph: " << std::endl;
                    g.printAdjLists();
                }
                else if (choice == -1)
                {
                    return 0;
                }
            }
        }

        else if (choice == 3)
        {
            if (isGraph)
            {
                std::cout << "Enter start vertex for BFS: ";
                std::cin >> strtV;
                while (strtV < 0)
                {
                    std::cout << "Start vertex must be >= 0: ";
                    std::cin >> strtV;
                }
                g.BFS(strtV);
                std::cout << std::endl;
            }
            else
            {
                std::cout << "You haven't entered the graph yet. Press 1 to do it or press -1 to exit the program: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    isGraph = true;
                    int dst;
                    std::cout << "Enter -1 to end entering an adjacency list!"
                              << "\n";
                    for (int i = 0; i < V; ++i)
                    {
                        dst = 0;
                        while (dst != -1)
                        {
                            std::cout << "Vertex " << i << ": ";
                            std::cin >> dst;
                            g.addEdge(i, dst);
                        }
                    }
                    g.sortAdj();

                    std::cout << std::endl;
                    std::cout << "Your graph: " << std::endl;
                    g.printAdjLists();
                }
                else if (choice == -1)
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
}

void Graph::addEdge(int src, int dst)
{
    adjLists[src].push_back(dst);
}

void Graph::DFS(int strt)
{
    visited = new status[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        visited[i] = UNKNOWN;
    }
    std::stack<int> S;
    S.push(strt);
    while (!S.empty())
    {
        int curr = S.top();
        S.pop();
        if (visited[curr] == VISITED)
        {
            continue;
        }
        visited[curr] = VISITED;
        for (auto i = adjLists[curr].begin(); i != adjLists[curr].end(); ++i)
        {
            if (*i == -1)
            {
                break;
            }
            if (visited[*i] != VISITED)
            {
                S.push(*i);
            }
        }
        std::cout << curr << "\t";
    }
    delete[] visited;
}

void Graph::BFS(int strt)
{
    visited = new status[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        visited[i] = UNKNOWN;
    }
    std::queue<int> Q;
    Q.push(strt);

    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        visited[curr] = VISITED;

        for (auto i = adjLists[curr].begin(); i != adjLists[curr].end(); ++i)
        {
            if (*i == -1)
            {
                break;
            }
            if (visited[*i] == UNKNOWN)
            {
                Q.push(*i);
                visited[*i] = DISCOVERED;
            }
        }
        std::cout << curr << "\t";
    }
    delete[] visited;
}

void Graph::sortAdj()
{
    for (int i = 0; i < numVertices; ++i)
    {
        adjLists[i].sort();
    }
}

void Graph::printAdjLists()
{
    for (int i = 0; i < numVertices; ++i)
    {
        std::cout << i;
        for (auto j = adjLists[i].begin(); j != adjLists[i].end(); ++j)
        {
            if (*j != -1)
            {
                std::cout << " -> " << *j;
            }
        }
        std::cout << std::endl;
    }
}

void printMenu()
{
    std::cout << "\n\n"
              << "        "
              << "Menu" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "| 1. Enter Graph   |" << std::endl;
    std::cout << "| 2. DFS           |" << std::endl;
    std::cout << "| 3. BFS           |" << std::endl;
    std::cout << "--------------------" << std::endl;
}
