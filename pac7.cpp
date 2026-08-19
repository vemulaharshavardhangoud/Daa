#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            int coin = coins[j];

            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                int value = dp[i - coin] + 1;

                // Instead of min()
                if (value < dp[i])
                {
                    dp[i] = value;
                }
            }
        }
    }

    if (dp[amount] == INT_MAX)
    {
        return -1;
    }

    return dp[amount];
}

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);

    if (result == -1)
    {
        cout << "Amount cannot be formed." << endl;
    }
    else
    {
        cout << "Minimum number of coins required = "
             << result << endl;
    }

    return 0;
}