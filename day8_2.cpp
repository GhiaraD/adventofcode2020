#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
fstream f("day8.in");

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
    vector<string> v;
    bool prez[1001] = {0};
    string s, nr;
    int rez = 0;
    while (getline(f, s))
        v.push_back(s);
    for (long unsigned int i = 0; i < v.size(); ++i)
    {
        if (prez[i] == true)
        {
            cout << rez << '\n';
            return 0;
        }
        prez[i] = true;
        if (v[i][0] == 'n')
            continue;
        else if (v[i][0] == 'a')
        {
            nr = v[i].substr(5, v[i].length() - 5);
            if (v[i][4] == '+')
                rez += char_to_int(nr);
            else
                rez -= char_to_int(nr);
        }
        else
        {
            nr = v[i].substr(5, v[i].length() - 5);
            if (v[i][4] == '+')
                i += char_to_int(nr) - 1;
            else
                i -= char_to_int(nr) + 1;
        }
    }
    return 0;
}
