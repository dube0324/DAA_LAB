// 0/1 Knapsack Problem
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, w;
    cout << "Enter n,w (nW): ";
    cin >> n >> w;
    int W[n + 1];
    int val[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value and weight of item " << i << ": ";
        cin >> val[i] >> W[i];
    }
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = 0;
            else if (W[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], val[i] + dp[i - 1][j - W[i]]);
        }
    }
    cout << "Maximum value is: " << dp[n][w] << endl;
    return 0;
}