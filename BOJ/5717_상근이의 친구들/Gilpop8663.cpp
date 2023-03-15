#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        cout << n + m << "\n";
    }
}
