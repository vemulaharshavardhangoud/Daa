#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Start time
    auto start = high_resolution_clock::now();

    int selected[10] = {0};
    selected[0] = 1;

    int edges = 0;
    int total = 0;

    cout << "\nMST Edges:\n";

    while (edges < n - 1) {
        int min = 9999;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << endl;

        total += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    // End time
    auto end = high_resolution_clock::now();

    // Calculate time
    auto time = duration_cast<microseconds>(end - start);

    cout << "\nTotal cost = " << total << endl;
    cout << "Execution time = " << time.count()
         << " microseconds" << endl;

    return 0;
}