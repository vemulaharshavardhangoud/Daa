
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    int n, capacity;

    // Get number of items
    cout << "Enter number of items: ";
    cin >> n;

    int weight[20], value[20];

    // Input weights
    cout << "Enter weights: ";
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    // Input values
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
        cin >> value[i];

    // Input knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[20][100];

    // Start execution time
    auto start = high_resolution_clock::now();

    // Initialize DP table
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            // Base condition
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            // If item weight is less than capacity
            else if(weight[i-1] <= w)
            {
                dp[i][w] = max(
                    value[i-1] + dp[i-1][w-weight[i-1]],
                    dp[i-1][w]
                );
            }

            // If item cannot be included
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // End execution time
    auto end = high_resolution_clock::now();

    // Calculate execution time
    auto nano = duration_cast<nanoseconds>(end - start);
    auto micro = duration_cast<microseconds>(end - start);
    auto milli = duration_cast<milliseconds>(end - start);

    // Display maximum value
    cout << "\nMaximum value = " << dp[n][capacity];

    // Display execution time
    cout << "\n\n========== EXECUTION TIME ==========\n";
    cout << "Nanoseconds  : " << nano.count() << " ns\n";
    cout << "Microseconds : " << micro.count() << " us\n";
    cout << "Milliseconds : " << milli.count() << " ms\n";

    return 0;
}
