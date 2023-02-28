#include <bits/stdc++.h>
using namespace std;

int n;

int arr[4];
bool ch[4];

int dp[65][65][65];

int atk[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {1, 3, 9},
    {3, 1, 9},
    {3, 9, 1},
    {1, 9, 3},
};

queue<tuple<int, int, int>> q;

// const int INF = 1e9;

// int find(int a, int b, int c)
// {
//     if (a < 0)
//     {
//         return find(0, b, c);
//     }
//     if (b < 0)
//     {
//         return find(a, 0, c);
//     }
//     if (c < 0)
//     {
//         return find(a, b, 0);
//     }

//     if (dp[a][b][c] != INF)
//     {
//         return dp[a][b][c];
//     }

//     if (a == 0 && b == 0 && c == 0)
//     {
//         return 0;
//     }

//     dp[a][b][c] = 12345678;

//     dp[a][b][c] = min(dp[a][b][c], find(a - 9, b - 3, c - 1) + 1);
//     dp[a][b][c] = min(dp[a][b][c], find(a - 9, b - 1, c - 3) + 1);
//     dp[a][b][c] = min(dp[a][b][c], find(a - 3, b - 9, c - 1) + 1);
//     dp[a][b][c] = min(dp[a][b][c], find(a - 1, b - 9, c - 3) + 1);
//     dp[a][b][c] = min(dp[a][b][c], find(a - 1, b - 3, c - 9) + 1);
//     dp[a][b][c] = min(dp[a][b][c], find(a - 3, b - 1, c - 9) + 1);

//     return dp[a][b][c];
// }

int bfs(int a, int b, int c)
{

    dp[a][b][c] = 1;
    q.push({a, b, c});

    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        if (dp[0][0][0])
            break;

        for (int i = 0; i < 6; i++)
        {
            int nx = max(0, x - atk[i][0]);
            int ny = max(0, y - atk[i][1]);
            int nz = max(0, z - atk[i][2]);
            if (dp[nx][ny][nz])
                continue;
            dp[nx][ny][nz] = dp[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }

    return dp[0][0][0] - 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // fill(&dp[0][0][0], &dp[64][64][65], INF);

    // cout << find(arr[0], arr[1], arr[2]);

    cout << bfs(arr[0], arr[1], arr[2]);
}
