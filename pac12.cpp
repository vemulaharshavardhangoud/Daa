
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;

    // Get number of cities
    cout << "Enter number of cities: ";
    cin >> n;

    int cost[10][10];

    // Read cost matrix
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int path[10];

    // Initialize city numbers
    for (int i = 0; i < n; i++) {
        path[i] = i;
    }

    int minCost = 999999;
    int bestPath[10];

    // Generate all possible permutations
    do {
        // Start every tour from city 0
        if (path[0] != 0)
            continue;

        int totalCost = 0;
        bool valid = true;

        // Calculate cost between consecutive cities
        for (int i = 0; i < n - 1; i++) {
            if (cost[path[i]][path[i + 1]] == 99999) {
                valid = false;
                break;
            }

            totalCost += cost[path[i]][path[i + 1]];
        }

        // Add cost to return to starting city
        if (cost[path[n - 1]][path[0]] == 99999)
            valid = false;
        else
            totalCost += cost[path[n - 1]][path[0]];

        // Update minimum cost and best path
        if (valid && totalCost < minCost) {
            minCost = totalCost;

            for (int i = 0; i < n; i++) {
                bestPath[i] = path[i];
            }
        }

    } while (next_permutation(path, path + n));

    // Display minimum travelling cost
    if (minCost == 999999) {
        cout << "No valid tour exists.\n";
    }
    else {
        cout << "\nMinimum travelling cost: "
             << minCost << endl;

        cout << "Optimal path: ";

        for (int i = 0; i < n; i++) {
            cout << bestPath[i] + 1 << " -> ";
        }

        cout << bestPath[0] + 1 << endl;
    }

    return 0;
}
