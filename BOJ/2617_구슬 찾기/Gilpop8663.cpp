#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr[105];
vector<int> Rarr[105];
bool ch[105];
bool Rch[105];

queue<int> q;
int cnt = 0;
int rcnt = 0;

void reset()
{
    cnt = 0;
    rcnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ch[i] = 0;
        Rch[i] = 0;
    }
    fill(Rch, Rch + n, 0);
    fill(ch, ch + n, 0);
}

void bfs(int start)
{
    ch[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        for (int j = 0; j < arr[num].size(); j++)
        {
            int nxtNum = arr[num][j];

            if (ch[nxtNum] == 1)
                continue;
            ch[nxtNum] = 1;
            cnt += 1;
            q.push(nxtNum);
        }
    }
}

void rbfs(int start)
{
    Rch[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        for (int j = 0; j < Rarr[num].size(); j++)
        {
            int nxtNum = Rarr[num][j];

            if (Rch[nxtNum] == 1)
                continue;
            rcnt += 1;
            Rch[nxtNum] = 1;
            q.push(nxtNum);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        Rarr[b].push_back(a);
    }

    int ans = 0;
    int base = (n + 1) / 2;
    for (int i = 1; i <= n; i++)
    {

        reset();
        bfs(i);
        rbfs(i);
        if (cnt >= base || rcnt >= base)
        {
            ans += 1;
        }
    }

    cout << ans;
}
