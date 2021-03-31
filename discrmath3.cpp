#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <limits>

struct Graph
{
    int vertices{0};
    bool *visited{nullptr};
    int *labels{nullptr};
    int *parent{nullptr};
    int **initArray{nullptr};
    std::vector<int> path;
    std::list<std::pair<int, int>> *adjLists{nullptr};
    Graph(int V);
    ~Graph();

    void addEdge(int src, int dst, int w);
    void minFord(int vStart, int vFinish);
    void print();
};

int main()
{

    const int V = 7;
    // const int V = 10;
    Graph g(V);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 2, 3);
    g.addEdge(3, 4, 4);
    g.addEdge(3, 5, 2);
    g.addEdge(3, 6, 8);
    g.addEdge(4, 6, 3);
    g.addEdge(5, 4, 2);
    g.addEdge(5, 6, 6);

    // g.addEdge(0, 1, 1);
    // g.addEdge(0, 2, 4);
    // g.addEdge(0, 7, 8);
    // g.addEdge(1, 3, 4);
    // g.addEdge(1, 5, 5);
    // g.addEdge(2, 3, 3);
    // g.addEdge(2, 4, 3);
    // g.addEdge(3, 5, 5);
    // g.addEdge(3, 6, 2);
    // g.addEdge(4, 8, 3);
    // g.addEdge(4, 9, 4);
    // g.addEdge(5, 7, 2);
    // g.addEdge(5, 9, 7);
    // g.addEdge(6, 4, 3);
    // g.addEdge(6, 7, 1);
    // g.addEdge(7, 9, 2);
    // g.addEdge(8, 7, 5);
    // g.addEdge(8, 9, 3);

    g.print();
    g.minFord(0, V - 1);
    return 0;
}

Graph::Graph(int V)
{
    vertices = V;
    visited = new bool[vertices];
    labels = new int[vertices];
    parent = new int[vertices];
    initArray = new int *[vertices];
    for (int i = 0; i < vertices; ++i)
    {
        initArray[i] = new int[vertices];
    }

    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            initArray[i][j] = -1;
        }
    }
    adjLists = new std::list<std::pair<int, int>>[vertices];
}

void Graph::addEdge(int src, int dst, int w)
{
    adjLists[src].push_back(std::make_pair(dst, w));
}

void Graph::print()
{
    for (int i = 0; i < vertices; ++i)
    {
        if (adjLists[i].size() == 0)
        {
            std::cout << i << " -> NULL";
        }
        else
        {
            std::cout << i;
        }
        for (auto j = adjLists[i].begin(); j != adjLists[i].end(); ++j)
        {
            std::cout << " -> " << j->first << "(" << j->second << ")";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

Graph::~Graph()
{
    delete[] adjLists;
    adjLists = nullptr;
    delete[] labels;
    labels = nullptr;
    delete[] visited;
    visited = nullptr;
    delete[] parent;
    parent = nullptr;
    for (int i = 0; i < vertices; ++i)
    {
        delete[] initArray[i];
    }
    delete[] initArray;
    initArray = nullptr;
}

void Graph::minFord(int vStart, int vFinish)
{

    // =================== <Ford Algorithm> =================== //

    const int INF = std::numeric_limits<int>::max();

    initArray[0][0] = 0;
    for (int i = 1; i < vertices; ++i)
    {
        initArray[0][i] = INF;
    }

    for (int i = 0; i < vertices; ++i)
    {
        visited[i] = false;
        labels[i] = INF;
        parent[i] = -1;
    }
    labels[vStart] = 0;

    for (int i = 0; i < vertices; i++)
    {
        int nearestV = -1;
        for (int v = 0; v < vertices; v++)
            if (!visited[v] && (nearestV == -1 || labels[v] < labels[nearestV]))
                nearestV = v;

        visited[nearestV] = true;

        for (auto &e : adjLists[nearestV])
        {
            int to = e.first, w = e.second;
            if (labels[to] > labels[nearestV] + w)
            {
                labels[to] = labels[nearestV] + w;
                initArray[i + 1][to] = labels[to];
                parent[to] = nearestV;
            }
        }
    }

    ///////////////////////////////////////Print Array/////////////////////////////////////////////////
    for (int i = 0; i < vertices; ++i)
    {
        initArray[vertices - 1][i] = labels[i];
    }

    std::cout << "\t";
    for (int i = 0; i < vertices; ++i)
    {
        std::cout << "x" << i << "\t";
    }
    std::cout << "\n";

    for (int i = 0; i < vertices; ++i)
    {
        if (i == vertices - 1)
        {
            std::cout << "l"
                      << "\t";
        }
        else
        {
            std::cout << "s" << i + 1 << "\t";
        }
        for (int j = 0; j < vertices; ++j)
        {
            if (initArray[i][j] == INF)
            {
                std::cout << "\u221E"
                          << "\t";
            }
            else if (initArray[i][j] == -1)
            {
                std::cout << "-"
                          << "\t";
            }
            else
            {
                std::cout << initArray[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////

    for (int v = vFinish; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    std::cout << "\n";
    for (auto it = path.begin(); it != path.end(); ++it)
    {
        if ((it + 1) != path.end())
        {
            std::cout << *it << " -> ";
        }
        else
        {
            std::cout << *it;
        }
    }

    // =================== </Ford Algorithm> =================== //
}