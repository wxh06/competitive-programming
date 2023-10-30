/*
ID: wangxin22
TASK: milk2
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

unsigned count_continuous(bool *a, unsigned s, unsigned e, bool v)
{
    unsigned c = 0, r = 0;
    for (unsigned i = s; i < e; i++)
    {
        if (i && a[i] != a[i - 1])
            c = 0;
        if (a[i] == v)
            c++;
        r = std::max(c, r);
    }
    return r;
}

int main()
{
    unsigned short n;
    unsigned s = 1000000, e = 0;
    bool t[1000000] = {};
    freopen("milk2.in", "r", stdin);
    std::cin >> n;
    for (unsigned short i = 0; i < n; i++)
    {
        unsigned a, b;
        std::cin >> a >> b;
        s = std::min(a, s);
        e = std::max(b, e);
        std::fill(t + a, t + b, true);
    }
    fclose(stdin);
    freopen("milk2.out", "w", stdout);
    std::cout << count_continuous(t, s, e, 1) << " " << count_continuous(t, s, e, 0) << std::endl;
    fclose(stdout);
    return 0;
}
