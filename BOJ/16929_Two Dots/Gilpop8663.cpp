#include <bits/stdc++.h>
using namespace std;

int n, m;

char arr[55][55];

bool ch[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int stX, stY;

bool isAns = 0;

void func(int x, int y, int count)
{

    ch[x][y] = 1;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (arr[nx][ny] != arr[x][y])
            continue;
        if (nx == stX && ny == stY && count >= 4)
        {
            isAns = 1;
            return;
        }
        if (ch[nx][ny] == 1)
            continue;
        func(nx, ny, count + 1);
    }
    ch[x][y] = 0;
    return;
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
            arr[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ch[i][j] == 1)
                continue;
            stX = i;
            stY = j;
            func(i, j, 1);

            // cout << cur.first << " " << cur.second << "\n";
        }
    }

    if (isAns == 1)
    {
        cout << "Yes";
        return 0;
    }
    else
    {

        cout << "No";
    }
}
