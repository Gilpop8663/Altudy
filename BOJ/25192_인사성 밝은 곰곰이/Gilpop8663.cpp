#include <bits/stdc++.h>
using namespace std;

int n;

set<string> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "ENTER")
        {
            ans += s.size();
            s.clear();
            continue;
        }

        s.insert(str);
    }

    ans += s.size();

    cout << ans;
}
