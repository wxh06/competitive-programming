/*
ID: wangxin22
TASK: ride
LANG: C
*/

#include <stdio.h>

int main () {
    freopen ("ride.in",  "r", stdin);
    freopen ("ride.out", "w", stdout);
    char s1[7] = {0}, s2[7] = {0};
    int c1 = 1, c2 = 1;
    scanf ("%s\n%s", s1, s2);
    for (int i = 0; s1[i] != '\0'; i++)
        c1 *= s1[i] - 64;
    for (int i = 0; s2[i] != '\0'; i++)
        c2 *= s2[i] - 64;
    if (c1 % 47 == c2 % 47)
        printf ("GO\n");
    else
        printf ("STAY\n");
    return 0;
}
