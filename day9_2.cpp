#include <bits/stdc++.h>

using namespace std;
fstream f("day9.in");

#define pre 26

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
    long long x[pre], weakness, sum_part[1001], numbers[1001];
    int i = 0;
    while (f >> x[i % pre])
    {
        if (i)
            sum_part[i] = sum_part[i - 1] + x[i % pre];
        else
            sum_part[0] = x[0];
        numbers[i] = x[i % pre];
        if (i >= pre - 1)
        {
            if (!check_sum(x, pre, x[i % pre]))
            {
                weakness = x[i % pre];
                break;
            }
        }
        i++;
    }
    for (int j = 0; j < i; ++j)
    {
        for (int k = j + 1; k < i; ++k)
        {
            int s = 0;
            if (!j)
                s = sum_part[k];
            else
                s = sum_part[k] - sum_part[j - 1];
            if (s == weakness)
            {
                //cout << numbers[j] << ' ' << numbers[k] << '\n';
                long long min = LONG_LONG_MAX, max = LONG_LONG_MIN;
                for (int h = j; h < k; ++h)
                {
                    if (numbers[h] > max)
                        max = numbers[h];
                    if (numbers[h] < min)
                        min = numbers[h];
                }
                cout << max + min << '\n';
            }
        }
    }
    return 0;
}
