#include <bits/stdc++.h>
using namespace std;

int n1, n2, n3;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n1 >> n2 >> n3;

    int ans = (n1 + 1) * (n2 + 1) / (n3 + 1) - 1;

    cout
        << ans;
}