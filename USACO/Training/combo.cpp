/*
ID: wangxin22
TASK: combo
LANG: C++
*/

#include <cmath>
#include <cstdio>
#include <algorithm>

short diff(short n, short a, short b)
{
    return std::min(abs(a - b), std::min(abs(a - b + n), abs(a - b - n)));
}

int main()
{
    short a, b, c, n, x, y, z;
    freopen("combo.in", "r", stdin);
    scanf("%hd\n%hd %hd %hd\n%hd %hd %hd", &n, &x, &y, &z, &a, &b, &c);
    fclose(stdin);
    unsigned cnt = 0;
    for (short i = 0; i < n; i++)
        for (short j = 0; j < n; j++)
            for (short k = 0; k < n; k++)
                if ((diff(n, x, i) <= 2 && diff(n, y, j) <= 2 && diff(n, z, k) <= 2) ||
                    (diff(n, a, i) <= 2 && diff(n, b, j) <= 2 && diff(n, c, k) <= 2))
                    cnt++;
    freopen("combo.out", "w", stdout);
    printf("%u\n", cnt);
    fclose(stdout);
    return 0;
}
