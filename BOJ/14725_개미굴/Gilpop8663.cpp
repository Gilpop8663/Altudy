#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105];

set<string> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        string str;
        for (int j = 0; j < k; j++)
        {
            string way;
            cin >> way;
            str += '*';
            str += way;
            s.insert(str);
        }
    }

      for (auto str : s)
    {
        int cnt = count(str.begin(), str.end(), '*') - 1;
        int pos = str.find_last_of("*");
        string tmp = str.substr(pos + 1);
        for (int i = 0; i < cnt; i++)
        {
            cout << "--";
        }
        cout << tmp << "\n";
    }
}
