#include <iostream>
#include <fstream>
#include <climits>

using namespace std;
fstream f("day13.in");

int char_to_int(string s)
{
    int rez = 0, p = 1;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        rez += p * (s[i] - '0');
        p *= 10;
    }
    return rez;
}

int main()
{
    int v[100] = {0}, k = 0, v2[100], v3[100], l = 0;
    string s;
    getline(f, s);
    cout << s << '\n';
    for (int i = 0; i < s.length(); ++i)
    {
        bool ok = false;
        int len = 0, start = i;
        while (s[i] != ',')
        {
            if (s[i] == 'x')
            {
                v[k++] = -1;
                break;
            }
            len++;
            i++;
            ok = true;
        }
        if (ok)
            v[k++] = char_to_int(s.substr(start, len));
    }

    //int ok = 1, count = 0;

    for (int i = 0; i < k; ++i)
        if (v[i] != -1)
        {
            v2[l] = v[i];
            v3[l++] = i;
        }

    for (int i = 0; i < l; ++i)
        cout << v2[i] << ' ';
    cout << '\n';
    for (int i = 0; i < l; ++i)
        cout << v3[i] << ' ';
    cout << '\n';

    // bool ok = false;
    // long long val = 0;
    // int start;
    // for (int i = 0; i < k; ++i)
    //     if (v[i] != -1)
    //     {
    //         start = i;
    //         break;
    //     }
    // while (!ok)
    // {
    //     ok = true;
    //     val += v[start];
    //     cout << val << ' ';
    //     for (int i = start + 1; i < k; ++i)
    //         if (v[i] != -1 && (val + i) % v[i] != 0)
    //         {
    //             ok = false;
    //             break;
    //         }
    // }
    // cout << val << '\n';
    return 0;
}