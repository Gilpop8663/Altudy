#include <bits/stdc++.h>
using namespace std;

double n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    double minus = n * m / 100;

    if (n - minus < 100)
    {
        cout << 1;
        return 0;
    }
    cout << 0;
}
