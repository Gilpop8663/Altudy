#include <bits/stdc++.h>
using namespace std;

int n, m;

int t;

vector<int> adj[1001];

queue<int> q;

int deg[1001];

vector<int> result;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        int prev;

        cin >> prev;

        for (int j = 0; j < num - 1; j++)
        {
            int number;
            cin >> number;

            adj[prev].push_back(number);
            deg[number] += 1;
            prev = number;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        result.push_back(num);

        for (int nxt : adj[num])
        {
            deg[nxt] -= 1;

            if (deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }

    if (result.size() != n)
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << result[i] << "\n";
        }
    }
}
