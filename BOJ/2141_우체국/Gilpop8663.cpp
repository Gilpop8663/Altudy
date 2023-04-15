#include <bits/stdc++.h>
using namespace std;

int n;

pair<long long, long long> arr[100005];

long long psum[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        long long a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr + 1, arr + n + 1);

    int left = 1;
    int right = n;

    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + arr[i].second;
    }

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (psum[mid] >= psum[n] - psum[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << arr[left].first;
}
