#include <bits/stdc++.h>
using namespace std;

int n, m;

bool ch[100005];

vector<int> arr[100005];

int order[100005], DFS_path[100005], given_path[100005], L = 1;

bool comp(int a, int b)
{
    return order[a] < order[b];
}

void func(int k)
{
    ch[k] = 1;
    DFS_path[L++] = k;

    for (int i = 0; i < arr[k].size(); i++)
    {
        int num = arr[k][i];
        if (ch[num] == 1)
            continue;
        func(num);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int first, second;

        cin >> first >> second;

        arr[first].push_back(second);
        arr[second].push_back(first);
    }

    for (int i = 1; i <= n; i++)
    {
        int node;
        cin >> node;
        given_path[i] = node;
        order[node] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        sort(arr[i].begin(), arr[i].end(), comp);
    }

    func(1);

    for (int i = 1; i <= n; i++)
    {
        if (given_path[i] != DFS_path[i])
        {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}
