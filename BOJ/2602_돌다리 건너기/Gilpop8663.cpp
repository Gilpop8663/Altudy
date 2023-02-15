#include <bits/stdc++.h>
using namespace std;

string magic, bridge[3];

int dp[105][3][25];
int ans = 0;

int n;

int func(int idx, int kind, int magicIdx)
{
    if (magicIdx == magic.size())
    {
        return 1;
    }

    int &ret = dp[idx][kind][magicIdx];

    if (ret != -1)
        return ret;

    ret = 0;

    for (int i = idx; i < n; i++)
    {
        if (magic[magicIdx] == bridge[kind][i])
        {
            ret += func(i + 1, kind == 0 ? 1 : 0, magicIdx + 1);
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> magic >> bridge[0] >> bridge[1];

    n = bridge[0].size();

    memset(dp, -1, sizeof(dp));

    ans += func(0, 0, 0);
    ans += func(0, 1, 0);

    cout << ans;
}
