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

void schimba_pozitie(int *face, char parte, int grade)
{
    int sgn = 1;
    if (parte == 'L')
        sgn = -1;
    int nr = grade / 90;
    *face += sgn * nr;
    *face = *face % 4;
    if (*face < 0)
        *face = 4 + *face;
    //cout << *face << '\n';
}

void mergi_inainte(int face, int *x, int *y, int k)
{
    if (face == 0)
        *x += k;
    else if (face == 1)
        *y -= k;
    else if (face == 2)
        *x -= k;
    else if (face == 3)
        *y += k;
}

int main()
{
    string s;
    int face = 0;
    int x = 0, y = 0;
    while (f >> s)
    {
        string nr = s.substr(1, s.length() - 1);
        char command = s[0];
        int k = char_to_int(nr);
        //cout << command << k << '\n';

        if (command == 'N')
            y += k;
        else if (command == 'S')
            y -= k;
        else if (command == 'E')
            x += k;
        else if (command == 'W')
            x -= k;
        else if (command == 'R' || command == 'L')
            schimba_pozitie(&face, command, k);
        else if (command == 'F')
            mergi_inainte(face, &x, &y, k);

        //g << command << k << ' ' << x << ' ' << y << '\n';
    }
    cout << fabs(x) + fabs(y) << '\n';
    return 0;
}