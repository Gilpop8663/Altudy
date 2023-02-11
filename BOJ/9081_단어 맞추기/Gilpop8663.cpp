#include <bits/stdc++.h>
using namespace std;

int n;

string arr[12];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        string str = arr[i];

        sort(arr[i].begin(), arr[i].end(), greater<char>());

        if (str == arr[i])
        {
            cout << str << "\n";
            continue;
        }

        next_permutation(str.begin(), str.end());
        cout << str << "\n";
    }
}
