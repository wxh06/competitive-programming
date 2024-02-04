#include <stdio.h>

int main() {
    unsigned n, c = 0;
    scanf("%u", &n);
    for (unsigned i = 0; i <= n / 4; ++i)
        if (!((n - i * 4) % 5))
            c++;
    printf("%u", c);
    return 0;
}
