#include <bits/stdc++.h>

using namespace std;

int t, n;

string command[3] = {"+", "-", " "};
vector<int> arr;

string trimString(string originString)
{
    string nextString;

    for (int i = 0; i < originString.size(); i++)
    {
        if (originString[i] == ' ')
        {
            continue;
        }
        nextString += originString[i];
    }

    return nextString;
}

int calculate(int kind, int a, int b)
{
    if (kind == '+')
    {
        return a + b;
    }

    if (kind == '-')
    {
        return a - b;
    }

    return 0;
}

int calculateResult(string curString)
{
    int result = 0;

    int curNumber = 0;

    cout << curString << "\n";

    for (int i = 0; i < n; i++)
    {
        if (curString[i] == '+' || curString[i] == '-')
            break;
        cout << curNumber << "\n";
        curNumber *= 10;
        curNumber += (int)curString[i] - '0';
    }

    cout << curNumber << "\n";

    return curNumber;

    // for (int i = 0; i < curString.size(); i++)
    // {

    //     int curNumber = 0;

    //     if (curString[i] == '+' || curString[i] == '-')
    //     {
    //         result = calculate(curString[i], result, )
    //     }
    // }
}

string calculateString(int kind, string curString, int nextNumber)
{
    curString += command[kind];
    return curString += to_string(nextNumber);
}

void DFS(int k, string curString)
{
    if (k == n)
    {

        cout << trimString(curString) << "\n";

        return;
    }

    for (int i = 0; i < 3; i++)
    {
        string resultString = calculateString(i, curString, arr[k]);
        DFS(k + 1, resultString);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        arr.clear();

        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }

        string startString = to_string(arr[0]);

        // DFS(1, startString);

        calculateResult("12+3-4-56+7"); // -38
    }
}
