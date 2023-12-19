//
// Created by 汪心禾 on 2023/12/19.
//

#include <stdio.h>

#define X 1000002

long long barn[X], left[X], right[X];

long long waste(long long a, long long b, long long y) {
    return left[y] * a + right[y] * b;
}

int main() {
    long long max = 0, min = X, n, q;
    scanf("%lld\n", &n);
    for (long long i = 0; i < n; ++i) {
        long long x;
        scanf("%lld", &x);
        barn[x]++;
        min = x < min ? x : min;
        max = x > max ? x : max;
    }

    left[min] = 0;
    for (long long i = min + 1, j = 1; i <= max; ++i) {
        left[i] = left[i - 1] + j;
        j += barn[i];
    }

    right[max] = 0;
    for (long long i = max - 1, j = 1; i >= min; --i) {
        right[i] = right[i + 1] + j;
        j += barn[i];
    }

    scanf("%lld\n", &q);
    for (long long i = 0; i < q; ++i) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long l = min, r = max;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (waste(a, b, mid) > waste(a, b, mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        printf("%lld\n", waste(a, b, l));
    }

    return 0;
}
