#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
ifstream f("day3.in");

int main()
{
    char v[100001];
    int i = 0, count;
    f.getline(v, 100001);
    int size = strlen(v);
    while (f.getline(v, 100001))
    {
        i += 3;
        if (i >= size)
            i = i - size;
        if (v[i] == '#')
            count++;
    }
    cout << count<<'\n';
    return 0;
}