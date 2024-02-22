#include <stdio.h>

int main() {
    int c = 0, h[500000], n;
    scanf("%d", &n);
    for (int i = 0; i < n / 2; ++i)
        scanf("\n%d", h + i);
    for (int i = 0; i < n / 2; ++i) {
        int hi;
        scanf("\n%d", &hi);
        if (hi == h[i])
            c++;
    }
    printf("%d", c * 2);
    return 0;
}
