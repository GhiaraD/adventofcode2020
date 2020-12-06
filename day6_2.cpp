#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
fstream f("day6.in");

int main()
{
    map<char, int> questions;
    string x;
    int rez = 0, nr = 0;

    while (getline(f, x))
    {
        if (x.length() == 0)
        {
            for (auto &x : questions)
                if (x.second == nr)
                    rez += 1;
            questions.clear();
            nr = 0;
            cout << rez << '\n';
        }
        if (x.length())
            nr++;
        for (int i = 0; i < x.length(); ++i)
            if (questions.insert(make_pair(x[i], 1)).second == false)
                questions[x[i]]++;
    }
    cout << rez << '\n';
    return 0;
}