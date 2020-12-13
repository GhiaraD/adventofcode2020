#include <bits/stdc++.h>

using namespace std;
fstream f("day10.in");

int main()
{
    int v[1001], i = 0, diff[1001], nr = 1, op = 1;
    while (f >> v[i++])
        ;
    sort(v, v + i - 1);
    for (int j = 0; j < i - 1; ++j)
        diff[j + 1] = v[j + 1] - v[j];
    diff[0] = v[0];
    for (int j = i; j >= 0; --j)
    {
        int count = 0, ok = 0;
        if (diff[j] == 2 && diff[j - 1] == 1)
        {
            nr += op;
            count++;
        }
        if (diff[j] == 1 && diff[j - 1] == 2)
        {
            nr += op;
            count++;
        }
        if (j > 1 && diff[j] == 1 && diff[j - 1] == 1 && diff[j - 2] == 1)
        {
            nr += op;
            ok = 1;
        }
        if (diff[j] == 1 && diff[j - 1] == 1)
        {
            nr += op;
            if (!ok)
                count++;
        }
        op += count;
    }
    cout << nr << '\n';
    return 0;
}