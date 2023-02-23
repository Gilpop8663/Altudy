#include <bits/stdc++.h>
using namespace std;

int n;

int arr[135][135];
int dist[135][135];
bool ch[135][135];

queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func()
{
    fill(&dist[0][0], &dist[134][135], 1e9);

    dist[0][0] = arr[0][0];
    q.push({0, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (dist[nx][ny] <= dist[x][y] + arr[nx][ny])
                continue;
            dist[nx][ny] = dist[x][y] + arr[nx][ny];
            q.push({nx, ny});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    while (1)
    {
        cnt += 1;
        cin >> n;

        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        func();

        cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << "\n";
    }
}
