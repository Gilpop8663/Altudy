#include <bits/stdc++.h>
using namespace std;

int n, m, r;

vector<int> arr[100005];

queue<int> q;

bool ch[100005];

int ans[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i].size() > 0)
        {
            sort(arr[i].begin(), arr[i].end(), greater<int>());
        }
    }

    ch[r] = 1;
    q.push(r);

    int visit = 1;

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        ans[num] = visit;

        visit += 1;
        for (int i = 0; i < arr[num].size(); i++)
        {
            int nextNum = arr[num][i];

            if (ch[nextNum] == 1)
                continue;
            ch[nextNum] = 1;
            q.push(nextNum);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << "\n";
    }
}
