#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

#define length 10
#define max 1024

using namespace std;
fstream f("day5.in");

int main()
{
    char input[length + 2];
    bool prez[max] = {false};
    while (f.getline(input, length + 1))
    {
        int row = 0, seat = 0, id = 0;
        for (int k = 0; k < length - 3; ++k)
            if (input[k] == 'B')
                row += pow(2, length - 4 - k);

        for (int k = length - 3; k < length; ++k)
            if (input[k] == 'R')
                seat += pow(2, length - 1 - k);

        id = row * 8 + seat;
        prez[id] = true;
    }
    for (int i = 1; i < max - 1; ++i)
        if (!prez[i] && prez[i + 1] && prez[i - 1])
            cout << i << '\n';
    return 0;
}