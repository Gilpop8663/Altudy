#include <bits/stdc++.h>
using namespace std;

int n, m;

priority_queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
        {
            for (int j = 0; j < num; j++)
            {
                int number;
                cin >> number;
                q.push(number);
            }
        }
    }
}
