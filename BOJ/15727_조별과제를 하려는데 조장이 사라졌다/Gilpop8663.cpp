#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    if (n % 5 == 0)
    {
        cout << n / 5;
    }
    else
    {
        cout << n / 5 + 1;
    }
}
