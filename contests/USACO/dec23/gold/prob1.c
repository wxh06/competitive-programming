#include <stdbool.h>
#include <stdio.h>

#define N 751

int main() {
    int n;
    scanf("%d", &n);
    bool p[N][N];
    for (int i = 1; i < n; ++i) {
        scanf("\n");
        for (int j = i + 1; j <= n; ++j)
            p[i][j] = getchar() - '0';
    }

    bool d[N][N];
    for (int l = 1; l < n; ++l)
        for (int i = 1; i + l <= n; ++i) {
            int j = i + l;
            bool c = false;
            for (int k = i + 1; k < j; ++k)
                c = c != (d[i][k] && p[k][j]);
            d[i][j] = c != p[i][j];
        }

    int c = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            c += d[i][j];
    printf("%d", c);

    return 0;
}
