#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

#define length 10

using namespace std;
fstream f("day5.in");

int main()
{
    char input[length + 2];
    int maxid = 0;
    while (f.getline(input, length + 1))
    {
        //cout << input << '\n';
        int row = 0, seat = 0, id = 0;
        for (int k = 0; k < length - 3; ++k)
            if (input[k] == 'B')
                row += pow(2, length - 4 - k);
        //cout << row << '\n';
        for (int k = length - 3; k < length; ++k)
            if (input[k] == 'R')
                seat += pow(2, length - 1 - k);
        //cout << seat << '\n';
        id = row * 8 + seat;
        //cout << id << '\n';
        if (id > maxid)
            maxid = id;
    }
    cout << maxid << '\n';
    return 0;
}