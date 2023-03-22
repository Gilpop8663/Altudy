#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[250005];

int dp[250005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += arr[i];
    }

    dp[m] = sum;

    for (int i = m + 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + arr[i] - arr[i - m];
    }

    // for (int i = m; i <= n; i++)
    // {
    //     cout << dp[i] << " ";
    // }

    int maxNum = *max_element(dp, dp + n + 1);
    int cnt = 0;
    for (int i = m; i <= n; i++)
    {
        if (maxNum == dp[i])
        {
            cnt += 1;
        }
    }
    if (maxNum == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << maxNum << "\n";
        cout << cnt;
    }
}
