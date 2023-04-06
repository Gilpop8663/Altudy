#include <bits/stdc++.h>
using namespace std;

int t;

long long n;

bool isPrime(long long x)
{
    if (x < 2)
        return false;

    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}

long long nPrime(long long x)
{

    while (!isPrime(x))
    {
        x++;
    }

    return x;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << nPrime(n) << "\n";
    }
}
