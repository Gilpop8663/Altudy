#include <bits/stdc++.h>
using namespace std;

int n;

int arr[205];

int dp[205];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }

    int maxNum = *max_element(dp, dp + n);

    int ans = n - maxNum;

    cout << ans;
}