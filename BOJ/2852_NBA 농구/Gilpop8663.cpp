#include <bits/stdc++.h>
using namespace std;

int n;

int ans[30000][3];

int aTeam = 0;
int bTeam = 0;

int timer = 0;

int aTimer = 0;
int bTimer = 0;

string convertToTime(int number)
{
    string str;
    if (number / 60 < 10)
    {
        str = "0";
        str += to_string(number / 60);
    }
    else
    {
        str += to_string(number / 60);
    }
    str += ":";

    if (number % 60 < 10)
    {
        str += "0";
        str += to_string(number % 60);
    }
    else
    {
        str += to_string(number % 60);
    }

    return str;
}

int convertToSecond(string str)
{
    string minute = str.substr(0, 2);
    string second = str.substr(3, 2);

    int total = int(stoi(minute) * 60) + stoi(second);
    return total;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int saveTimer = 0;

    for (int i = 0; i < n; i++)
    {
        int team;
        string str;

        cin >> team >> str;

        int number = convertToSecond(str);

        if (i != 0)
        {
            if (aTeam > bTeam)
            {
                aTimer += number - saveTimer;
            }
            else if (aTeam < bTeam)
            {
                bTimer += number - saveTimer;
            }
        }

        if (team == 1)
        {
            aTeam += 1;
        }
        else
        {
            bTeam += 1;
        }

        saveTimer = number;

        if (i == n - 1)
        {
            if (aTeam > bTeam)
            {
                aTimer += 2880 - saveTimer;
            }
            else if (aTeam < bTeam)
            {
                bTimer += 2880 - saveTimer;
            }
        }
    }

    cout << convertToTime(aTimer) << "\n";
    cout << convertToTime(bTimer);
}
