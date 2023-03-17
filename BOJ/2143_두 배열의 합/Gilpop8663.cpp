#include <bits/stdc++.h>
using namespace std;

int T;

int n, m;

int aArr[1005];

int bArr[1005];
vector<int> aSum, bSum;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aArr[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> bArr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int sum = aArr[i];
        aSum.push_back(sum);

        for (int j = i + 1; j < n; j++)
        {
            sum += aArr[j];
            aSum.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int sum = bArr[i];
        bSum.push_back(sum);

        for (int j = i + 1; j < m; j++)
        {
            sum += bArr[j];
            bSum.push_back(sum);
        }
    }

    sort(bSum.begin(), bSum.end());

    long long ans = 0;

    for (int i = 0; i < aSum.size(); i++)
    {
        int target = T - aSum[i];
        int lo = lower_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
        int hi = upper_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
        ans += (hi - lo);
    }

    cout << ans;
}
