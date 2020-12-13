#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
fstream f("day7.in");

int main()
{
    string s, subs;
    map<string, int> colors;
    int k = 0;
    while (getline(f, s))
    {
        int found = 0, found2 = 0, lng = s.length();
        while (s.find("bag", found))
        {
            found = s.find("bag", found);
            subs = s.substr(found2, found - found2);
            found2 = s.find_first_of("0123456789");
        }
    }
    return 0;
}