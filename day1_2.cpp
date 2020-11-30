#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
ifstream f("day1.in");
map<int, pair<int, int>> sum;
vector<int> v;

int main()
{
    int x;
    while (f >> x)
        v.push_back(x);

    for (int i = 0; i < v.size() - 1; ++i)
        for (int j = i + 1; j < v.size(); ++j)
            sum[v[i] + v[j]] = make_pair(i, j);

    for (int i = 0; i < v.size(); ++i)
        if (sum.find(2020 - v[i]) != sum.end())
        {
            map<int, pair<int, int>>::iterator it = sum.find(2020 - v[i]);
            if (i != it->second.first && i != it->second.second)
            {
                cout << v[i] * v[it->second.first] * v[it->second.second];
                return 0;
            }
        }

    cout << "no pair";
    return 1;
}
