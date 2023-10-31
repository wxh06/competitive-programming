//
// Created by 汪心禾 on 2023/10/31.
//

/*
ID: wangxin22
TASK: wormhole
LANG: C
*/

#include <stdio.h>
#include <stdbool.h>

int n, wormholes[12][2], pairs[12], c;
bool paired[12];

bool trapped() {
    for (int start = 0; start < n; ++start) {
        int current = start;
        while (true) {
            current = pairs[current];
            int minX = 1000000000, next = -1;
            for (int i = 0; i < n; ++i)
                if (wormholes[i][1] == wormholes[current][1] && wormholes[i][0] > wormholes[current][0] &&
                    wormholes[i][0] < minX) {
                    minX = wormholes[i][0];
                    next = i;
                }
            if (next < 0) break;
            else if (next == start) return true;
            else current = next;
        }
    }
    return false;
}

void pair(int i) {
    if (i >= n / 2) {
        c += trapped();
        return;
    }
    int a;
    for (a = 0; a < n - 1; ++a)
        if (!paired[a])
            break;
    paired[a] = true;
    for (int b = a + 1; b < n; ++b)
        if (!paired[b]) {
            paired[b] = true;
            pairs[a] = b;
            pairs[b] = a;
            pair(i + 1);
            paired[b] = false;
        }
    paired[a] = false;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("\n%d %d", wormholes[i], wormholes[i] + 1);
    pair(0);
    freopen("wormhole.out", "w", stdout);
    printf("%d\n", c);
}
