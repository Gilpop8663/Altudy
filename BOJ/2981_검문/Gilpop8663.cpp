#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105];

set<int> ans;
vector<int> ansArr;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

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

    int gcdNum = arr[1] - arr[0];

    for (int i = 2; i < n; i++)
    {
        gcdNum = GCD(gcdNum, arr[i] - arr[i - 1]);
    }

    for (int i = 2; i * i <= gcdNum; i++)
    {
        if (gcdNum % i == 0)
        {
            ans.insert(i);
            ans.insert(gcdNum / i);
        }
    }

    ans.insert(gcdNum);

    for (auto num : ans)
    {
        ansArr.push_back(num);
    }

    sort(ansArr.begin(), ansArr.end());

    for (int i = 0; i < ansArr.size(); i++)
    {
        cout << ansArr[i] << " ";
    }
}