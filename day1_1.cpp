#include <iostream>
#include <fstream>
#include <map>

using namespace std;
fstream f("day1.in");

int main()
{
    int x;
    map<int, bool> sum;
    while (f >> x)
    {
        if (sum.find(2020 - x) != sum.end())
        {
            cout << x * (2020 - x) << '\n';
            return 0;
        }
        sum.insert(make_pair(x,true));
    }
    return 0;
}