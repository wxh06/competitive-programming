#include <stdio.h>
#include <stdbool.h>

int main() {
    int c, p = 0;
    scanf("%d", &c);
    bool color[2][200002];
    for (int i = 0; i < 2; ++i) {
        color[i][0] = false;
        for (int j = 1; j <= c; ++j) {
            int _c;
            scanf("%d", &_c);
            color[i][j] = _c;
        }
        color[i][c + 1] = false;
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= c; ++j)
            if (color[i][j])
                p += 3 - color[i][j - 1] - color[i][j + 1] - (j % 2 && color[!i][j]);
    printf("%d", p);
    return 0;
}
