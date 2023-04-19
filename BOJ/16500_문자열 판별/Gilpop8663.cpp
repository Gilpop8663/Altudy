#include <bits/stdc++.h>
using namespace std;

string word;

int n;

string arr[105];

bool dp[105] = {0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> word;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (dp[i] || i == 0)
        {
            int st = i;

            for (int j = 0; j < n; j++)
            {
                if (st + arr[j].length() > word.length())
                    continue;

                bool FLAG = 1;

                for (int k = 0; k < arr[j].length(); k++)
                {
                    if (arr[j][k] != word[st + k])
                    {
                        FLAG = 0;
                        break;
                    }
                }

                if (FLAG == 1)
                {
                    dp[st + arr[j].length()] = 1;
                }
            }
        }
    }

    cout << dp[word.length()];
}