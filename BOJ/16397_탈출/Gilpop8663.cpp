#include <bits/stdc++.h>
using namespace std;

int n, t, g;

bool ch[100005];

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t >> g;

    ch[n] = 1;
    q.push({n, t});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        if (x == g)
        {
            cout << t - y;
            return 0;
        }

        if (x < 0 || y <= 0)
        {
            continue;
        }

        if (ch[x + 1] == 0)
        {
            ch[x + 1] = 1;
            q.push({x + 1, y - 1});
        }

        int num = x * 2;

        if (num > 99999)
            continue;

        if (num >= 10000)
        {
            num -= 10000;
            if (ch[num] == 1)
                continue;
            ch[num] = 1;
            q.push({num, y - 1});
            continue;
        }

        if (num >= 1000)
        {
            num -= 1000;
            if (ch[num] == 1)
                continue;
            ch[num] = 1;
            q.push({num, y - 1});
            continue;
        }

        if (num >= 100)
        {
            num -= 100;
            if (ch[num] == 1)
                continue;
            ch[num] = 1;
            q.push({num, y - 1});
            ;
            continue;
        }

        if (num >= 10)
        {
            num -= 10;
            if (ch[num] == 1)
                continue;
            ch[num] = 1;
            q.push({num, y - 1});
            ;
            continue;
        }

        if (num >= 1)
        {
            num -= 1;
            if (ch[num] == 1)
                continue;
            ch[num] = 1;
            q.push({num, y - 1});
            ;
            continue;
        }

        if (num <= 0)
        {
            continue;
        }
    }

    cout << "ANG";
}
