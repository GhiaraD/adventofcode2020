#include <stdio.h>

int main()
{
    int v[1001], i = 0;
    while (v[i - 1] != -1)
    {
        scanf("%d", &v[i]);
        i++;
    }
    for (int k = 0; k < i - 1; ++k)
    {
        for (int j = k + 1; j < i - 1; ++j)
        {
            for (int y = j + 1; y < i - 1; ++y)
                if (v[k] + v[j] + v[y] == 2020)
                {
                    printf("%d\n", v[k] * v[j] * v[y]);
                    return 0;
                }
        }
    }
    return 0;
}