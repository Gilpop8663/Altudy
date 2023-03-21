#include <bits/stdc++.h>
using namespace std;

int n, m;

const int INF = 0x3f3f3f3f;

int arr[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        arr[num1][num2] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (arr[j][i] == 1 && arr[i][k] == 1)
                    arr[j][k] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (arr[i][j] == 0 && arr[j][i] == 0)
                cnt++;
        }
        cout << cnt << "\n";
    }
}
