#include <bits/stdc++.h>
using namespace std;

long long n;

const long long INF = 100000000;

void Nfunc(long long cnt, long long testCase, long long limit)
{
    long long number = (cnt * testCase);

    long long timeLimit = (limit * INF);

    if (number <= timeLimit)
    {
        cout << "May Pass."
             << "\n";
    }
    else
    {
        cout << "TLE!"
             << "\n";
    }
    return;
}

void twoNfunc(long long cnt, long long testCase, long long limit)
{

    if (cnt >= 30)
    {
        cout << "TLE!"
             << "\n";
        return;
    }

    long long timeLimit = (limit * INF);

    long long number = testCase * (long long)pow(2, cnt);

    if (number <= timeLimit)
    {
        cout << "May Pass."
             << "\n";
    }
    else
    {
        cout << "TLE!"
             << "\n";
    }
    return;
}

void importfunc(long long cnt, long long testCase, long long limit)
{
    if (cnt >= 13)
    {
        cout << "TLE!"
             << "\n";
        return;
    }

    long long timeLimit = (limit * INF);

    long long number = testCase;

    for (long long i = 1; i <= cnt; i++)
    {
        number *= i;
    }

    if (number <= timeLimit)
    {
        cout << "May Pass."
             << "\n";
    }
    else
    {
        cout << "TLE!"
             << "\n";
    }
    return;
}

void secondfunc(long long cnt, long long testCase, long long limit)
{

    if (cnt >= 31623)
    {
        cout << "TLE!"
             << "\n";
        return;
    }

    long long timeLimit = (limit * INF);

    long long number = (cnt * cnt * testCase);

    if (number <= timeLimit)
    {
        cout << "May Pass."
             << "\n";
    }
    else
    {
        cout << "TLE!"
             << "\n";
    }
    return;
}

void thirdfunc(long long cnt, long long testCase, long long limit)
{

    if (cnt >= 1001)
    {
        cout << "TLE!"
             << "\n";
        return;
    }

    long long timeLimit = limit * INF;

    long long number = (cnt * cnt * cnt * testCase);

    if (number <= timeLimit)
    {
        cout << "May Pass."
             << "\n";
    }
    else
    {
        cout << "TLE!"
             << "\n";
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        string str;
        long long m, t, l;

        cin >> str >> m >> t >> l;
        if (str == "O(N)")
        {
            Nfunc(m, t, l);
        }
        else if (str == "O(2^N)")
        {
            twoNfunc(m, t, l);
        }
        else if (str == "O(N!)")
        {
            importfunc(m, t, l);
        }
        else if (str == "O(N^3)")
        {
            thirdfunc(m, t, l);
        }
        else if (str == "O(N^2)")
        {
            secondfunc(m, t, l);
        }
    }
}
