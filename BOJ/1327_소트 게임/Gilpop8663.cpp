#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[10];

int BFS(string s)
{
    queue<pair<string, int>> q;
    q.push({s, 0});
    map<string, bool> visited;
    string target = s;
    sort(target.begin(), target.end());

    while (!q.empty())
    {
        string cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (cur == target)
        {
            return cnt;
        }

        if (!visited.count(cur))
        {
            visited[cur] = true;
            for (int i = 0; i <= n - k; i++)
            {
                string tmp = cur.substr(i, k);
                reverse(tmp.begin(), tmp.end());

                q.push({cur.substr(0, i) + tmp + cur.substr(i + k, cur.size()), cnt + 1});
            }
        }
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    string str;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        str += c;
    }

    cout << BFS(str);
}
