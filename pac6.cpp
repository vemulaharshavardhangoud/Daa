#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[100], value[100];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[100][100];

    auto start = high_resolution_clock::now();

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    auto end = high_resolution_clock::now();

    auto nano = duration_cast<nanoseconds>(end - start);
    auto micro = duration_cast<microseconds>(end - start);
    auto milli = duration_cast<milliseconds>(end - start);

    cout << "\n========== 0/1 KNAPSACK ==========\n";
    cout << "Maximum value : " << dp[n][capacity] << endl;

    cout << "\n========== EXECUTION TIME ==========\n";
    cout << "Nanoseconds  : " << nano.count() << " ns\n";
    cout << "Microseconds : " << micro.count() << " us\n";
    cout << "Milliseconds : " << milli.count() << " ms\n";

    return 0;
}