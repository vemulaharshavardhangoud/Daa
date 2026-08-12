#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Graph
{
    int vertices;
    vector<vector<int>> graph;

public:
    Graph(int n)
    {
        vertices = n;
        graph.resize(vertices);
    }

    void addEdge(int a, int b)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void DFSHelper(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int next : graph[node])
        {
            if (!visited[next])
            {
                DFSHelper(next, visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(vertices, false);
        DFSHelper(start, visited);
    }

    void BFS(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int next : graph[node])
            {
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
};

int main()
{
    int vertices, edges;

    cout << "Enter vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter edges: ";
    cin >> edges;

    cout << "Enter edge pairs:\n";

    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;

        g.addEdge(a, b);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    auto time1 = high_resolution_clock::now();

    cout << "\nDFS: ";
    g.DFS(start);

    auto time2 = high_resolution_clock::now();

    auto dfsTime = duration_cast<nanoseconds>(time2 - time1);

    auto time3 = high_resolution_clock::now();

    cout << "\nBFS: ";
    g.BFS(start);

    auto time4 = high_resolution_clock::now();

    auto bfsTime = duration_cast<nanoseconds>(time4 - time3);

    cout << "\n\nExecution Time:";
    cout << "\nDFS Time: " << dfsTime.count() << " ns";
    cout << "\nBFS Time: " << bfsTime.count() << " ns";

    return 0;
}