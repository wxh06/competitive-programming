#include <stdio.h>

int main() {
    unsigned n, h[10000], a = 0;
    scanf("%u", &n);
    for (unsigned i = 0; i <= n; ++i)
        scanf("%u", h + i);
    for (unsigned i = 0; i < n; ++i) {
        unsigned w;
        scanf("%u", &w);
        a += (h[i] + h[i + 1]) * w;
    }
    printf("%.1f", (float) a / 2);
    return 0;
}
