#include <bits/stdc++.h>
using namespace std;

int n, m, r;

vector<int> arr[200005];

bool ch[200005] = {0};

vector<int> ans;

int ansArr[200005];

bool cmp(int x, int y)
{
    if (x > y)
        return true;
    else
        return false;
}

void DFS(int start)
{
    ans.push_back(start);

    for (int i = 0; i < arr[start].size(); i++)
    {
        int num = arr[start][i];
        if (ch[num] == 1)
            continue;
        ch[num] = 1;
        DFS(num);
    }
}

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
        if (arr[i].empty())
            continue;

        sort(arr[i].begin(), arr[i].end(), cmp);
    }

    ch[r] = 1;

    DFS(r);

    int ansSize = ans.size();

     for (int i = 0; i < ansSize; i++)
    {
        ansArr[ans[i]] = i + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ansArr[i] << "\n";
    }
}
