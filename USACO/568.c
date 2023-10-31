#include <stdio.h>

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int m, n, limit[100], actual[100], e = 0;
    freopen("speeding.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0, p = 0; i < n; ++i) {
        int l, s;
        scanf("\n%d %d", &l, &s);
        for (int j = 0; j < l; ++j)
            limit[p++] = s;
    }
    for (int i = 0, p = 0; i < m; ++i) {
        int l, s;
        scanf("\n%d %d", &l, &s);
        for (int j = 0; j < l; ++j)
            actual[p++] = s;
    }
    for (int i = 0; i < 100; ++i)
        e = max(actual[i] - limit[i], e);
    freopen("speeding.out", "w", stdout);
    printf("%d", e);
    return 0;
}
