#include <bits/stdc++.h>
using namespace std;

long long n;

long long func(long long x)
{
    if (x == 1)
        return 0;
    long long i;
    for (i = 1; i + i < x; i += i)
        ;

    return !func(x - i);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << func(n);
}
