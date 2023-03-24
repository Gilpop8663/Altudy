#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int target = arr[i];
        int left = 0;
        int right = n - 1;
        int sum = 0;

        while (left < right)
        {
            sum = arr[left] + arr[right];
            if (sum == target)
            {
                if (i != left && i != right)
                {
                    result += 1;
                    break;
                }
                else if (left == i)
                    left += 1;
                else if (right == i)
                    right -= 1;
            }
            else if (sum < target)
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
    }

    cout << result;
    return 0;
}