#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
fstream f("day4.in");

int main()
{
    char input[100], *p;
    int count = 0, cid = 0, rez = 0;
    while (f.getline(input, 100))
    {
        if (strlen(input) == 0)
        {
            if (count == 8)
                rez++;
            if (count == 7 && !cid)
                rez++;
            //cout << count << ' ' << cid << '\n';
            cid = 0;
            count = 0;
            continue;
        }
        p = strtok(input, " ");
        while (p != NULL)
        {
            //cout << p[0] << '\n';
            if (p[0] == 'c')
                cid = 1;
            count++;
            p = strtok(NULL, " ");
        }
    }
    cout << rez << '\n';
    return 0;
}