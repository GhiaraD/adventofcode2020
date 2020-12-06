#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
fstream f("day6.in");

int main()
{
    map<char, bool> questions;
    string x;
    long long int rez = 0;
    while (getline(f, x))
    {
        if (x.length() == 0)
        {
            rez += questions.size();
            questions.clear();
        }
        for (int i = 0; i < x.length(); ++i)
        {
            questions.insert(make_pair(x[i], true));
        }
    }
    cout << rez << '\n';
    return 0;
}