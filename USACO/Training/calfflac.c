/*
ID: wangxin22
TASK: calfflac
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    char o[20000] = {}, s[20000] = {};
    unsigned len = 0, n = 0, m[20000] = {}, max = 1, l = 0, r = 0;
    freopen("calfflac.in", "r", stdin);
    while (scanf("%c", o + len) != -1)
        len++;
    fclose(stdin);
    for (unsigned i = 0; i < len; i++)
        if (o[i] >= 'a' && o[i] <= 'z')
        {
            s[n] = o[i];
            m[n++] = i;
        }
        else if (o[i] >= 'A' && o[i] <= 'Z')
        {
            s[n] = o[i] - 'A' + 'a';
            m[n++] = i;
        }
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; ++j;)
            if (i < j || i + j >= n || s[i - j] != s[i + j])
            {
                if (max < --j * 2 + 1)
                {
                    max = j * 2 + 1;
                    l = i - j;
                    r = i + j;
                }
                break;
            }
        for (unsigned j = 0; ++j;)
            if (i >= j - 1 && i + j < n && s[i - j + 1] == s[i + j])
            {
                if (max < j * 2)
                {
                    max = j * 2;
                    l = i - j + 1;
                    r = i + j;
                }
            }
            else
                break;
    }
    freopen("calfflac.out", "w", stdout);
    printf("%u\n", max);
    for (unsigned i = m[l]; i <= m[r]; i++)
        printf("%c", o[i]);
    printf("\n");
    fclose(stdout);
    exit(0);
}
