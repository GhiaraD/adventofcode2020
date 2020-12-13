#include <bits/stdc++.h>

using namespace std;
fstream f("day9.in");

#define pre 6

int check_sum(long long x[], int n, long long nr)
{
    long long copy[1001];
    for (int i = 0; i < n; ++i)
        copy[i] = x[i];
    sort(copy, copy + n);

    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (copy[l] + copy[r] == nr)
        {
            //cout << copy[l] << ' ' << copy[r] << '\n';
            return 1;
        }
        else if (copy[l] + copy[r] < nr)
            l++;
        else
            r--;
    }
    return 0;
}

int main()
{
    long long x[pre];
    int i = 0;
    while (f >> x[i % pre])
    {
        if (i >= pre - 1)
        {
            if (!check_sum(x, pre, x[i % pre]))
            {
                cout << x[i % pre] << '\n';
                return 0;
            }
        }
        i++;
    }
    return 0;
}
