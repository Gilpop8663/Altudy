#include <bits/stdc++.h>
using namespace std;

string str;

stack<char> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (s.empty())
        {
            s.push(str[i]);
            continue;
        }
        if (s.top() == '(' && str[i] == ')')
        {
            s.pop();
            continue;
        }
        s.push(str[i]);
    }

    cout << s.size();
}
