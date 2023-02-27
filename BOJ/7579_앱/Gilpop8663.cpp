#include <bits/stdc++.h>
using namespace std;

int n, m;

int bite[105];

int cost[105];

int dp[105][10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> bite[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j - cost[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bite[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i;
            break;
        }
    }
}
