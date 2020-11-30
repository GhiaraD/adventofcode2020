#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[101], passwd[5];
    int low, high, rez = 0;
    while (low != -1)
    {
        cin >> low;
        cin.get();
        cin >> high;
        cin.get(passwd, 5);
        cin.getline(s, 100);
        if (s[low - 1] == passwd[1] && s[high - 1] != passwd[1])
            rez++;
        else if (s[low - 1] != passwd[1] && s[high - 1] == passwd[1])
            rez++;
    }
    cout << rez << '\n';
    return 0;
}