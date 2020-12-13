#include <bits/stdc++.h>

using namespace std;
fstream f("day10.in");

int main()
{
    int v[1001], i = 0, jolt_1 = 0, jolt_3 = 1;
    while (f >> v[i++])
        ;
    sort(v, v + i - 1);
    for (int j = 0; j < i - 1; ++j)
    {
        int diff = v[j + 1] - v[j];
        if (diff == 1)
            jolt_1++;
        else if (diff == 3)
            jolt_3++;
    }
    jolt_1 += v[0];
    cout << jolt_1 * jolt_3 << '\n';
    return 0;
}