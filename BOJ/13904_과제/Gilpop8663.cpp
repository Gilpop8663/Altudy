#include <bits/stdc++.h>
using namespace std;

int n;

vector<pair<int, int>> arr;

int cost[1005];

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int day, score;
        cin >> day >> score;
        arr.push_back({score, day});
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    int days = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].second; j > 0; j--)
        {
            if (!cost[j])
            {
                cost[j] = arr[i].first;
                ans += arr[i].first;
                break;
            }
        }
    }

    cout << ans;
}
