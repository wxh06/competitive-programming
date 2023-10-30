/*
ID: wangxin22
TASK: transform
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <iostream>

const unsigned short N = 10;

void transform(unsigned short n, char a[N][N], unsigned short t)
{
    char b[N][N];
    memcpy(b, a, N * N);
    if (t < 4)
    {
        for (unsigned short i = 0; i < n; i++)
            for (unsigned short j = 0; j < n; j++)
                a[j][n - i - 1] = b[i][j];
        if (t - 1)
            transform(n, a, t - 1);
    }
    else if (t == 4)
        for (unsigned short i = 0; i < n; i++)
            for (unsigned short j = 0; j < n; j++)
                a[i][n - j - 1] = b[i][j];
    else if (t > 50)
    {
        transform(n, a, 4);
        transform(n, a, t - 50);
    }
}

bool valid(unsigned short n, char s[3][N][N], unsigned short t)
{
    memcpy(s[2], s[0], N * N);
    transform(n, s[2], t);
    return !memcmp(s[1], s[2], N * N);
}

unsigned short transformation(unsigned short n, char s[3][N][N])
{
    for (unsigned short i = 1; i != 7; i++)
    {
        if (i == 5)
            i = 51;
        else if (i == 54)
            i = 6;
        if (valid(n, s, i))
            return i > 50 ? 5 : i;
    }
    return 7;
}

int main()
{
    unsigned short n;
    char s[3][N][N] = {};
    freopen("transform.in", "r", stdin);
    scanf("%hu", &n);
    for (unsigned short i = 0; i < 2; i++)
        for (unsigned short j = 0; j < n; j++)
        {
            scanf("\n");
            for (unsigned short k = 0; k < n; k++)
                scanf("%c", &s[i][j][k]);
        }
    fclose(stdin);
    freopen("transform.out", "w", stdout);
    std::cout << transformation(n, s) << std::endl;
    fclose(stdout);
    return 0;
}
