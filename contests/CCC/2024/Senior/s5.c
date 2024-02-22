//
// Created by 汪心禾 on 2024/2/22.
//

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define N 2000

int n, t[2][N], split[2][N], max = 0;

void dfs(int x, int y, double mean, int cnt, int sum, int num) {
    split[x][y] = num;

    if (fabs((double) sum / cnt - mean) < 0.00001) {
        bool full = true;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < n; ++j)
                if (!split[i][j]) {
                    full = false;
                    dfs(i, j, mean, 1, t[i][j], num + 1);
                }
        if (full && num > max)
            max = num;
    }

    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j) {
            int newX = x + i, newY = y + j;
            if (abs(i) + abs(j) < 2 && newX >= 0 && newX < 2 && newY >= 0 && newY < n && !split[newX][newY])
                dfs(newX, newY, mean, cnt + 1, sum + t[newX][newY], num);
        }

    split[x][y] = 0;
}

int main() {
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < n; ++j) {
            scanf("%d", t[i] + j);
            sum += t[i][j];
        }

    double mean = sum / 2.0 / n;
    if (!sum)
        max = n * 2;
    for (int i = 1; i < sum; ++i)
        if (!(sum % i))
            dfs(0, 0, mean, 1, t[0][0], 1);
    printf("%d", max);
    return 0;
}
