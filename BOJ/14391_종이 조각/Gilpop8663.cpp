#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[6][6];

bool ch[6][6];

int ans = 0;

void dfs(int num, int sum)
{
    int x = num / m;
    int y = num % m;
    if (num >= n * m)
    {
        ans = max(ans, sum);
        return;
    }

    if (ch[x][y] == 1)
    {
        dfs(num + 1, sum);
    }
    else
    {
        int val, nx, ny;
        val = arr[x][y];
        ch[x][y] = 1;
        dfs(num + 1, sum + val);
        ch[x][y] = 0;

        // 밑으로
        for (int k = 1; k < n - x; k++)
        {

            int nx = x + k;
            int ny = y;
            val *= 10;
            val += arr[nx][ny];

            for (int i = 1; i <= k; i++)
            {
                ch[x + i][ny] = 1;
            }

            dfs(num + 1, sum + val);

            for (int i = 1; i <= k; i++)
            {
                ch[x + i][ny] = 0;
            }
        }
        val = arr[x][y];
        // 오른쪽으로
        for (int k = 1; k < m - y; k++)
        {
            int nx = x;
            int ny = y + k;
            if (ch[nx][ny] == 1)
                return;
            val *= 10;
            val += arr[nx][ny];

            for (int i = 1; i <= k; i++)
            {
                ch[nx][y + i] = 1;
            }
            dfs(num + 1, sum + val);
            for (int i = 1; i <= k; i++)
            {
                ch[nx][y + i] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    dfs(0, 0);
    cout << ans;
}
