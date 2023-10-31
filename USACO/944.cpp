#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>

int minX, minY, maxX, maxY;

void search(std::set<int> *e, int *x, int *y, bool *v, int cow) {
    if (v[cow])
        return;
    v[cow] = true;
    for (std::set<int>::iterator i = e[cow].begin(); i != e[cow].end(); ++i) {
        if (minX >= 0) {
            minX = std::min(x[cow], minX);
            minY = std::min(y[cow], minY);
            maxX = std::max(x[cow], maxX);
            maxY = std::max(y[cow], maxY);
        } else {
            minX = x[cow];
            minY = y[cow];
            maxX = x[cow];
            maxY = y[cow];
        }
        search(e, x, y, v, *i);
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int m, n, x[100000], y[100000], minP = 400000000;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> y[i];
    std::set<int> e[100000];
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        e[a - 1].insert(b - 1);
        e[b - 1].insert(a - 1);
    }
    bool v[100000];
    std::fill(v, v + n, false);
    for (int i = 0; i < n; ++i)
        if (!v[i]) {
            minX = -1;
            minY = -1;
            maxX = -1;
            maxY = -1;
            search(e, x, y, v, i);
            minP = std::min(((maxX - minX) + (maxY - minY)) * 2, minP);
        }
    std::cout << minP;
    return 0;
}
