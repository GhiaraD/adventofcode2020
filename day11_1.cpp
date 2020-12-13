#include <iostream>
#include <fstream>
#include <string>

using namespace std;
fstream f("day11.in");

int check_adiacent(char mat[][100], int i, int j)
{
    int count = 0;
    if (mat[i - 1][j - 1] != '#')
        count++;
    if (mat[i - 1][j] != '#')
        count++;
    if (mat[i - 1][j + 1] != '#')
        count++;
    if (mat[i][j - 1] != '#')
        count++;
    if (mat[i][j + 1] != '#')
        count++;
    if (mat[i + 1][j - 1] != '#')
        count++;
    if (mat[i + 1][j] != '#')
        count++;
    if (mat[i + 1][j + 1] != '#')
        count++;
    return count;
}

bool change(char mat[][100], int n, int m)
{
    bool ok = false;
    char copy[100][100] = {0};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int count = check_adiacent(mat, i, j);
            if (mat[i][j] == 'L')
            {
                if (count == 8)
                {
                    copy[i][j] = '#';
                    ok = true;
                }
                else
                    copy[i][j] = mat[i][j];
            }
            else if (mat[i][j] == '#')
            {
                if (count <= 4)
                {
                    copy[i][j] = 'L';
                    ok = true;
                }
                else
                    copy[i][j] = mat[i][j];
            }
            else
            {
                copy[i][j] = mat[i][j];
                //cout << mat[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            mat[i][j] = copy[i][j];
        }
    }
    return ok;
}

int main()
{
    char matrix[100][100];
    string s;
    int j = 0, nr = 0, nrop = 0;
    bool ok = true;

    while (getline(f, s))
    {
        for (long unsigned int i = 0; i < s.length(); ++i)
            matrix[j][i] = s[i];
        j++;
    }
    // for (int i = 0; i < j; ++i)
    // {
    //     for (long unsigned int k = 0; k < s.length(); ++k)
    //     {
    //         cout << matrix[i][k];
    //     }
    //     cout << '\n';
    // }
    while (ok)
    {
        ok = change(matrix, j, s.length());
        nrop++;
    }
    for (int i = 0; i < j; ++i)
        for (long unsigned int k = 0; k < s.length(); ++k)
            if (matrix[i][k] == '#')
                nr++;
    cout << nrop - 1 << ' ' << nr << '\n';
    return 0;
}