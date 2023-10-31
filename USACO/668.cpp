//
// Created by 汪心禾 on 2022/11/3.
//

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <iostream>

int dfs(std::set<int>* e, bool* v, int node) {
    v[node] = true;
    int r = 1;
    for (std::set<int>::iterator i = e[node].begin(); i != e[node].end(); ++i)
        if (!v[*i])
            r += dfs(e, v, *i);
    return r;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n, r = 0;
    std::set<int> e[200];
    std::cin >> n;
    for (int i = 0, p[200], x[200], y[200]; i < n; ++i) {
        std::cin >> x[i] >> y[i] >> p[i];
        for (int j = 0; j < i; ++j) {
            double d = sqrt(pow((x[i] - x[j]), 2) + pow(y[i] - y[j], 2));
            if (d < p[i])
                e[i].insert(j);
            if (d < p[j])
                e[j].insert(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        bool v[200];
        std::fill(v, v + 200, false);
        r = std::max(r, dfs(e, v, i));
    }

    std::cout << r << std::endl;
}
