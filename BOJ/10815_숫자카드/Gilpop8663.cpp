#include <bits/stdc++.h>
using namespace std;

int n;

int arr1[500005];

int m;
int arr2[500005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    sort(arr1, arr1 + n);

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        cout << binary_search(arr1, arr1 + n, num) << " ";
    }
}
