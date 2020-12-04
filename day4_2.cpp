#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;
fstream f("day4.in");

int main()
{
    char input[100], *p, comp[100];
    int count = 0, cid = 0, rez = 0;
    while (f.getline(input, 100))
    {
        if (strlen(input) == 0)
        {
            if (count == 8)
                rez++;
            if (count == 7 && !cid)
                rez++;
            cout << count << ' ' << cid << '\n';
            cid = 0;
            count = 0;
            continue;
        }
        p = strtok(input, " ");
        while (p != NULL)
        {
            if (p[0] == 'c')
            {
                cid = 1;
                count++;
            }
            else if (p[0] == 'b' && p[1] == 'y' && p[2] == 'r')
            {
                if (strlen(p) == 8)
                {
                    strcpy(comp, p + 4);
                    if (strcmp(comp, "1920") >= 0 && strcmp(comp, "2002") <= 0)
                        count++;
                    memset(comp, 0, 100);
                }
            }
            else if (p[0] == 'i' && p[1] == 'y' && p[2] == 'r')
            {
                if (strlen(p) == 8)
                {
                    strcpy(comp, p + 4);
                    if (strcmp(comp, "2010") >= 0 && strcmp(comp, "2020") <= 0)
                        count++;
                    memset(comp, 0, 100);
                }
            }
            else if (p[0] == 'e' && p[1] == 'y' && p[2] == 'r')
            {
                if (strlen(p) == 8)
                {
                    strcpy(comp, p + 4);
                    if (strcmp(comp, "2020") >= 0 && strcmp(comp, "2030") <= 0)
                        count++;
                    memset(comp, 0, 100);
                }
            }
            else if (p[0] == 'p' && p[1] == 'i' && p[2] == 'd')
            {
                if (strlen(p) == 13)
                {
                    int ok = 1;
                    strcpy(comp, p + 4);
                    for (int i = 0; i < strlen(comp); ++i)
                        if (!isdigit(comp[i]))
                            ok = 0;
                    if (ok)
                        count++;
                    memset(comp, 0, 100);
                }
            }
            else if (p[0] == 'e' && p[1] == 'c' && p[2] == 'l')
            {
                if (strlen(p) == 7)
                {
                    strcpy(comp, p + 4);
                    if (strcmp(comp, "amb") == 0 || strcmp(comp, "blu") == 0 || strcmp(comp, "brn") == 0 || strcmp(comp, "gry") == 0 || strcmp(comp, "grn") == 0 || strcmp(comp, "hzl") == 0 || strcmp(comp, "oth") == 0)
                        count++;
                    memset(comp, 0, 100);
                }
            }
            else if (p[0] == 'h' && p[1] == 'c' && p[2] == 'l')
            {
                if (strlen(p) == 11)
                {
                    strcpy(comp, p + 4);
                    if (comp[0] == '#')
                    {
                        int ok=1;
                        for (int i = 1; i < strlen(comp); ++i)
                        {
                            if (!isdigit(comp[i]))
                                if(comp[i] > 'f' || comp[i] < 'a')
                                {
                                    ok=0;
                                }
                        }
                        if(ok)count++;
                    }
                    memset(comp, 0, 100);
                }
            }
            else if (p[0] == 'h' && p[1] == 'g' && p[2] == 't')
            {
                if (p[strlen(p) - 1] == 'n')
                {
                    if (strlen(p) == 8)
                    {
                        strcpy(comp, p + 4);
                        if (comp[0] == '6' || (comp[0] == '5' && comp[1] == '9') || (comp[0] == '7' && isdigit(comp[1]) && comp[1] < '7'))
                            count++;
                        memset(comp, 0, 100);
                    }
                }
                else if (p[strlen(p) - 1] == 'm')
                {
                    if (strlen(p) == 9)
                    {
                        strcpy(comp, p + 4);
                        if (comp[0] == '1')
                            if (comp[1] == '5' || comp[1] == '6' || comp[1] == '7' || comp[1] == '8' || (comp[1] == '9' && isdigit(comp[2]) && comp[2] < '4'))
                                count++;
                        memset(comp, 0, 100);
                    }
                }
            }
            p = strtok(NULL, " ");
        }
    }
    cout << rez << '\n';
    return 0;
}