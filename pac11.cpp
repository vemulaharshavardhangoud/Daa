
#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int n;

    // Get number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    int dist[10][10];

    // Read adjacency matrix
    cout << "Enter adjacency matrix (99999 for no edge):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    // k represents the intermediate vertex
    for (int k = 0; k < n; k++) {

        // Select source vertex
        for (int i = 0; i < n; i++) {

            // Select destination vertex
            for (int j = 0; j < n; j++) {

                // Check if a shorter path exists through k
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    // Update shortest distance
                    dist[i][j] =
                        dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Display shortest distance matrix
    cout << "\nAll-Pairs Shortest Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
