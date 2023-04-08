#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[200005];

int dp[200005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    int result = 0;

    int left = 0;
    int right = 0;

    while (1)
    {
        if (left == n || right == n)
            break;
        int leftNum = arr[left];
        int rightNum = arr[right];

        // cout << left << " " << right << "\n";

        if (dp[rightNum] < m)
        {
            dp[rightNum] += 1;
            right += 1;
            result += 1;
            ans = max(ans, result);
            continue;
        }

        dp[leftNum] -= 1;
        left += 1;
        result -= 1;
    }

    cout << ans << "\n";
}
