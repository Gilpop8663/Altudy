#include <bits/stdc++.h>
using namespace std;

int n;

int arr[505][505];

int dp[505][505];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int DFS(int x, int y)
{

    if (dp[x][y] != 1)
        return dp[x][y];

    int &result = dp[x][y];

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if (arr[x][y] >= arr[nx][ny])
            continue;

        result = max(result, DFS(nx, ny) + 1);
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(&dp[0][0], &dp[504][505], 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, DFS(i, j));
        }
    }

    cout << ans;
}