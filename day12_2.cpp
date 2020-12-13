#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;
ifstream f("day12.in");
ofstream g("day12.out");

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

void schimba_pozitie(int *facex, int *facey, char parte, int grade)
{
    int sgn;
    int nr = grade / 90;
    if (nr != 4)
    {
        if (parte == 'L')
        {
            if (nr == 3)
            {
                nr = 1;
                sgn = 1;
            }
            else
                sgn = -1;
        }
        else
        {
            if (nr == 3)
            {
                nr = 1;
                sgn = -1;
            }
            else
                sgn = 1;
        }

        if (nr == 1)
        {
            int tmp = -sgn * (*facex);
            *facex = sgn * (*facey);
            *facey = tmp;
        }
        if (nr == 2)
        {
            *facex = -*facex;
            *facey = -*facey;
        }
    }
}

void mergi_inainte(int facex, int facey, int *x, int *y, int k)
{
    *x += k * facex;
    *y += k * facey;
}

int main()
{
    string s;
    int facex = 10;
    int facey = 1;
    int x = 0, y = 0;
    while (f >> s)
    {
        string nr = s.substr(1, s.length() - 1);
        char command = s[0];
        int k = char_to_int(nr);

        if (command == 'N')
            facey += k;
        else if (command == 'S')
            facey -= k;
        else if (command == 'E')
            facex += k;
        else if (command == 'W')
            facex -= k;
        else if (command == 'R' || command == 'L')
            schimba_pozitie(&facex, &facey, command, k);
        else if (command == 'F')
            mergi_inainte(facex, facey, &x, &y, k);
        g << command << k << ' ' << facex << ' ' << facey << ' ' << x << ' ' << y << '\n';
    }
    cout << fabs(x) + fabs(y) << '\n';
    return 0;
}