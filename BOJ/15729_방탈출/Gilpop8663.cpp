#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            ans += 1;
            arr[i] = 0;
            arr[i + 1] = arr[i + 1] == 1 ? 0 : 1;
            arr[i + 2] = arr[i + 2] == 1 ? 0 : 1;
        }
    }

    cout << ans;
}
