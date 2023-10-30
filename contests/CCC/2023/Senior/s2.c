#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, h[5000], av[5000][5000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", h + i);

    // Initial states
    for (int i = 0; i < n; ++i)
        av[i][i] = 0;
    for (int i = 0; i < n - 1; ++i)
        av[i][i + 1] = abs(h[i] - h[i + 1]);

    for (int mid = 0; mid < n; ++mid)
        for (int len = 1; mid - len >= 0 && mid + len < n; ++len)
            av[mid - len][mid + len] = av[mid - len + 1][mid + len - 1] + abs(h[mid - len] - h[mid + len]);
    for (int mid = 0; mid < n; ++mid)
        for (int len = 1; mid - len - 1 >= 0 && mid + len < n; ++len)
            av[mid - len - 1][mid + len] = av[mid - len][mid + len - 1] + abs(h[mid - len - 1] - h[mid + len]);

    for (int len = 0; len < n; ++len) {
        int min = 2147483647;
        for (int l = 0; l < n - len; ++l) {
            int r = l + len;
            min = av[l][r] < min ? av[l][r] : min;
        }
        printf("%d ", min);
    }
    return 0;
}
