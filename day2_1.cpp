#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[101], passwd[5];
    int low, high, nr, rez = 0;
    while (low != -1)
    {
        cin >> low;
        cin.get();
        cin >> high;
        cin.get(passwd, 5);
        cin.getline(s, 100);
        nr = 0;
        for (int i = 0; i < strlen(s); ++i)
        {
            if (s[i] == passwd[1])
                nr++;
        }
        if (nr >= low && nr <= high)
            rez++;
    }
    cout << rez << '\n';
    // cout << low << ' ' << high << ' ';
    // for (int i = 0; i < strlen(passwd); ++i)
    //     cout << passwd[i];
    return 0;
}