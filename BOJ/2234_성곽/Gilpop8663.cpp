#include <bits/stdc++.h>
using namespace std;

int n, m;

queue<pair<int, int>> q;

int arr[55][55];
int ch[55][55];

int room_area[2555];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int roomCnt, cnt;

int maxRoom = 0;

void printCh()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ch[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int i, int j)
{
    roomCnt += 1;
    ch[i][j] = roomCnt;
    q.push({i, j});

    int cnt = 1;

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

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (ch[nx][ny] != 0)
                continue;

            if ((arr[x][y] & (1 << k)) == 0)
            {
                ch[nx][ny] = roomCnt;
                q.push({nx, ny});
                cnt += 1;
            }
        }
    }

    room_area[roomCnt] = cnt;

    maxRoom = max(maxRoom, cnt);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int brokenCnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ch[i][j] != 0)
                continue;
            bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int x = i;
            int y = j;

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if ((arr[x][y] & (1 << k)) == 1)
                    continue;
                if (ch[x][y] == ch[nx][ny])
                    continue;
                int sum = room_area[ch[x][y]] + room_area[ch[nx][ny]];
                brokenCnt = max(brokenCnt, sum);
            }
        }
    }

    cout << roomCnt << "\n";
    cout << maxRoom << "\n";
    cout << brokenCnt;
}
