#include <bits/stdc++.h>
using namespace std;

int n;

int arr[34][34];

long long dp[34][34][3]; // 동, 남 , 대각선

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (arr[i][j] == 1)
                continue;

            if (arr[i][j + 1] == 0)
            {
                dp[i][j + 1][0] = dp[i][j][2] + dp[i][j][0];
            }
            if (arr[i + 1][j] == 0)
            {
                dp[i + 1][j][1] = dp[i][j][2] + dp[i][j][1];
            }
            if (i + 1 < n && j + 1 < n)
            {
                if (arr[i + 1][j] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j + 1] == 0)
                {
                    dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
                }
            }
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}
