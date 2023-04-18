#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> arr[100005];

priority_queue<int, vector<int>, greater<int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr + n);

    q.push(arr[0].second);

    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        while (!q.empty() && q.top() <= arr[i].first)
        {
            q.pop();
        }

        q.push(arr[i].second);
        ans = max(ans, (int)q.size());
    }

    cout << ans;
}
