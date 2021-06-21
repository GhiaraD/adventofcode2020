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
    int time, v[100], k = 0, minim = INT_MAX, id = 0;
    string s;
    f >> time;
    f.get();
    getline(f, s);
    cout << time << ' ' << s << '\n';
    for (int i = 0; i < s.length(); ++i)
    {
        bool ok = false;
        int len = 0, start = i;
        while (s[i] != ',' && s[i] != 'x')
        {
            len++;
            i++;
            ok = true;
        }
        if (ok)
            v[k++] = char_to_int(s.substr(start, len));
    }
    for (int i = 0; i < k; ++i)
    {
        int mult = 0;
        while (mult < time)
            mult += v[i];
        int dif = mult - time;
        if (dif < minim)
        {
            minim = dif;
            id = v[i];
        }
    }
    cout << minim << ' ' << id << '\n';
    return 0;
}