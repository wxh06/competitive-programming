//
// Created by 汪心禾 on 2024/2/22.
//

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int main() {
    int n, t;
    scanf("%d %d", &t, &n);
    while (t--) {
        char s[101];
        scanf("\n%s", s);
        int c[26];
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i)
            c[s[i] - 'a']++;
        bool heavy = c[s[0] - 'a'] > 1, valid = true;
        for (int i = 1; i < n; ++i) {
            heavy = !heavy;
            if ((c[s[i] - 'a'] > 1) != heavy) {
                printf("F");
                valid = false;
                break;
            }
        }
        if (valid)
            printf("T");
        printf("\n");
    }
}
