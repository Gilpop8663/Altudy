#include <bits/stdc++.h>
using namespace std;

int n, m;

bool ch[105];

int Price[105][105];

const int INF = 1e9;

int func(int k, int coupon)
{

    if (k > n)
        return 0;

    if (Price[k][coupon] != INF)
        return Price[k][coupon];

    if (ch[k] == 1)
    {
        Price[k][coupon] = func(k + 1, coupon);
        return Price[k][coupon];
    }

    Price[k][coupon] = min(Price[k][coupon], func(k + 1, coupon) + 10000);
    Price[k][coupon] = min(Price[k][coupon], func(k + 3, coupon + 1) + 25000);
    Price[k][coupon] = min(Price[k][coupon], func(k + 5, coupon + 2) + 37000);

    if (coupon >= 3)
    {
        Price[k][coupon] = min(Price[k][coupon], func(k + 1, coupon - 3));
    }

    return Price[k][coupon];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        ch[num] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            Price[i][j] = INF;
        }
    }

    int ans = func(1, 0);

    cout << ans;
}
