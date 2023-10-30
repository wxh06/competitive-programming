/*
ID: wangxin22
TASK: sprime
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(unsigned n)
{
    for (unsigned i = 2; i <= n / 2; i++)
        if (!(n % i))
            return 0;
    return n - 1;
}

void sprime(unsigned u, unsigned n)
{
    if (!is_prime(n))
        return;
    if (n >= u)
    {
        printf("%u\n", n);
        return;
    }
    for (unsigned i = 0 ? n : 1; i < 10; i++)
        sprime(u, n * 10 + i);
}

void main()
{
    unsigned short n;
    freopen("sprime.in", "r", stdin);
    scanf("%hu", &n);
    fclose(stdin);
    freopen("sprime.out", "w", stdout);
    sprime(pow(10, n - 1), 0);
    fclose(stdout);
    exit(0);
}
