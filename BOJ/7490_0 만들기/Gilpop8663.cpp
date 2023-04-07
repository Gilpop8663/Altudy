#include <bits/stdc++.h>

using namespace std;

int t, n;

string command[3] = {" ", "+", "-"};
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

pair<int, int> calculateNextNumber(int index, string curString)
{
    int curNumber = 0;
    int curIndex = 0;
    for (int i = index; i < curString.size(); i++)
    {
        curIndex = i;

        if (curString[i] == '+' || curString[i] == '-')
            break;

        curNumber *= 10;
        curNumber += (int)curString[i] - '0';
    }

    return {curNumber, curIndex + 1};
}

int calculateResult(string curString)
{
    int result = 0;
    int curNumber = 0;
    int curIndex = 0;

    pair<int, int> cur = calculateNextNumber(curIndex, curString);

    result = cur.first;
    curIndex = cur.second;

    while (curIndex < curString.size())
    {

        char curSign = curString[curIndex - 1];
        pair<int, int> cur = calculateNextNumber(curIndex, curString);

        curNumber = cur.first;
        curIndex = cur.second;

        result = calculate(curSign, result, curNumber);
    }

    return result;
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

        string resultString = trimString(curString);
        int result = calculateResult(resultString);
        if (result == 0)
        {
            cout << curString << "\n";
        }

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

        DFS(1, startString);
        cout << "\n";
    }
}
