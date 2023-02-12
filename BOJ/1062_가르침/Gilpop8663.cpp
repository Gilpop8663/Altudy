#include <bits/stdc++.h>
using namespace std;

int n, k;

string arr[55];

set<char> s;

vector<char> word;

vector<bool> check;

bool ch[60];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < arr[i].size(); j++)
        {
            char str = arr[i][j];
            if (str == 'a' || str == 'n' || str == 't' || str == 'i' || str == 'c')
                continue;
            s.insert(str);
        }
    }

    for (auto str : s)
    {
        word.push_back(str);
    }

    ch['a' - 'a'] = 1;
    ch['n' - 'a'] = 1;
    ch['t' - 'a'] = 1;
    ch['i' - 'a'] = 1;
    ch['c' - 'a'] = 1;

    // antic
    int lastWord = max(0, k - 5);

    if (k < 5)
    {
        cout << 0;
        return 0;
    }

    if (word.size() <= lastWord)
    {
        cout << n;
        return 0;
    }

    if (word.size() > 0)
    {

        sort(word.begin(), word.end());
    }

    int num = word.size() - lastWord;

    for (int i = 0; i < num; i++)
    {
        check.push_back(0);
    }

    for (int i = 0; i < lastWord; i++)
    {
        check.push_back(1);
    }

    int ans = 0;
    do
    {
        int count = 0;
        for (int i = 0; i < check.size(); i++)
        {
            if (check[i] == 1)
            {
                ch[word[i] - 'a'] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            bool isKnow = 1;
            for (int j = 0; j < arr[i].size(); j++)
            {
                int str = arr[i][j];
                if (ch[str - 'a'] == 0)
                {
                    isKnow = 0;
                    break;
                }
            }
            if (isKnow == 1)
            {
                count += 1;
            }
        }

        for (int i = 0; i < check.size(); i++)
        {
            if (check[i] == 1)
            {
                ch[word[i] - 'a'] = 0;
            }
        }
        ans = max(ans, count);
    } while (next_permutation(check.begin(), check.end()));

    cout << ans;
}
