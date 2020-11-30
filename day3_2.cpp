#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
ifstream f("day3.in");

int main()
{
    char v[100001];
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, count2 = 0, count1 = 0, count3 = 0, count4 = 0, count5 = 0;
    f.getline(v, 100001);
    int size = strlen(v);
    bool ok = 0;
    while (f.getline(v, 100001))
    {
        i1 += 1;
        if (i1 >= size)
            i1 = i1 - size;
        if (v[i1] == '#')
            count1++;

        i2 += 3;
        if (i2 >= size)
            i2 = i2 - size;
        if (v[i2] == '#')
            count2++;

        i3 += 5;
        if (i3 >= size)
            i3 = i3 - size;
        if (v[i3] == '#')
            count3++;

        i4 += 7;
        if (i4 >= size)
            i4 = i4 - size;
        if (v[i4] == '#')
            count4++;

        if (ok)
        {
            i5 += 1;
            if (i5 >= size)
                i5 = i5 - size;
            if (v[i5] == '#')
                count5++;
            ok = 0;
        }
        else
            ok = 1;
    }
    cout << count1 * count2 * count3 * count4 * count5 << '\n';
    return 0;
}