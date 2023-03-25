#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[100005];

int binary_search()
{
    int left = 0;
    int right = 100000;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int flag = 0;

        if (arr[0] > mid)
            flag = 1;

        for (int i = 0; i < m - 1; i++)
        {
            if (arr[i + 1] - arr[i] > mid * 2)
            {
                flag = 1;
                break;
            }
        }

        if (n - arr[m - 1] > mid)
            flag = 1;

        if (!flag)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    cout << binary_search();
}
