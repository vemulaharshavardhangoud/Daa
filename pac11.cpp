
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

    // Start execution time
    auto start = high_resolution_clock::now();

    // Floyd-Warshall Algorithm
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

    // End execution time
    auto end = high_resolution_clock::now();

    // Calculate execution time
    auto nano = duration_cast<nanoseconds>(end - start);
    auto micro = duration_cast<microseconds>(end - start);
    auto milli = duration_cast<milliseconds>(end - start);

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

    // Display execution time
    cout << "\n========== EXECUTION TIME ==========\n";
    cout << "Nanoseconds  : " << nano.count() << " ns\n";
    cout << "Microseconds : " << micro.count() << " us\n";
    cout << "Milliseconds : " << milli.count() << " ms\n";

    return 0;
}
