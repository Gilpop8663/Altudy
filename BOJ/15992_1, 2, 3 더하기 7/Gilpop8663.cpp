#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int t, n, m;

int dp[1005][1005];

int mod = 1000000009;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    dp[1][1] = 1, dp[2][1] = 1, dp[3][1] = 1;
    dp[2][2] = 1, dp[3][1] = 1, dp[3][2] = 2, dp[3][3] = 1;

    for (int i = 4; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 2][j - 1]) % mod + dp[i - 3][j - 1]) % mod;
        }
    }

    while (t--)
    {
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
}
