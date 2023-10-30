#include <stdio.h>
#include <stdbool.h>

int main() {
    int c, n, m, r;
    scanf("%d %d %d %d", &n, &m, &r, &c);
    char p[2000][2001];
    for (int i = 0; i < n; ++i)
        p[i][m] = '\0';
    bool possible = true;
    if (r == 1 && c == 1) {
        for (int i = 0; i < n; ++i)
            p[i][0] = 'a';
        for (int i = 0; i < m; ++i)
            p[0][i] = 'a';
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                p[i][j] = 'b';
    } else if (n == 2 && m == 2) {
        if (r == 2 && c == 2)
            p[0][0] = p[0][1] = p[1][0] = p[1][1] = 'a';
        else if (!r && !c) {
            p[0][0] = 'a';
            p[0][1] = 'b';
            p[1][0] = 'b';
            p[1][1] = 'a';
        } else if (r == 1 && !c) {
            p[0][0] = 'a';
            p[0][1] = 'a';
            p[1][0] = 'b';
            p[1][1] = 'c';
        } else if (!r && c == 1) {
            p[0][0] = 'a';
            p[0][1] = 'b';
            p[1][0] = 'a';
            p[1][1] = 'c';
        } else if (r == 2 && !c) {
            p[0][0] = 'a';
            p[0][1] = 'a';
            p[1][0] = 'b';
            p[1][1] = 'b';
        } else if (!r && c == 2) {
            p[0][0] = 'a';
            p[0][1] = 'b';
            p[1][0] = 'a';
            p[1][1] = 'b';
        } else possible = false;
    }
    if (possible)
        for (int i = 0; i < n; ++i)
            printf("%s\n", p[i]);
    else printf("IMPOSSIBLE");
    return 0;
}
