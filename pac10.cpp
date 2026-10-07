#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an edge
struct Edge {
  int u;      // Starting vertex
  int v;      // Ending vertex
  int weight; // Weight of edge
};

// Compare edges based on weight
bool compare(Edge a, Edge b) { return a.weight < b.weight; }

// Find the parent of a vertex
int findParent(int node, vector<int> &parent) {

  // If node is its own parent
  if (parent[node] == node)
    return node;

  // Path compression
  return parent[node] = findParent(parent[node], parent);
}

// Join two sets
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {

  // Find parents
  u = findParent(u, parent);
  v = findParent(v, parent);

  // If already in the same set, don't join
  if (u == v)
    return;

  // Union by rank
  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[u] > rank[v]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    rank[u]++;
  }
}

void kruskal(vector<Edge> &edges, int V) {

  // Sort all edges by increasing weight
  sort(edges.begin(), edges.end(), compare);

  // Initially every vertex is its own parent
  vector<int> parent(V);
  vector<int> rank(V, 0);

  for (int i = 0; i < V; i++) {
    parent[i] = i;
  }

  int totalWeight = 0;
  int edgesSelected = 0;

  cout << "Edges in Minimum Spanning Tree:\n";

  // Process edges one by one
  for (Edge edge : edges) {

    int u = edge.u;
    int v = edge.v;

    // Check whether adding this edge creates a cycle
    if (findParent(u, parent) != findParent(v, parent)) {

      // Add edge to MST
      cout << u << " - " << v << " : " << edge.weight << endl;

      totalWeight += edge.weight;
      edgesSelected++;

      // Merge the two sets
      unionSet(u, v, parent, rank);

      // MST contains V-1 edges
      if (edgesSelected == V - 1)
        break;
    }
  }

  cout << "\nMinimum Cost = " << totalWeight << endl;
}

int main() {

  int V, E;

  cout << "Enter number of vertices: ";
  cin >> V;

  cout << "Enter number of edges: ";
  cin >> E;

  vector<Edge> edges(E);

  cout << "\nEnter edges (u v weight):\n";

  for (int i = 0; i < E; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].weight;
  }

  kruskal(edges, V);

  return 0;
}