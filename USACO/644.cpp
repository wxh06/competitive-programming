#include <cstdio>
#include <iostream>
#include <set>

int find(int* id, int b) {
    if (id[b] != b)
        id[b] = find(id, id[b]);
    return id[b];
}

bool unite(int* id, int b1, int b2) {
    int f1 = find(id, b1), f2 = find(id, b2);
    id[f1] = f2;
    return f1 != f2;
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int m, n, o[3001], rm[3001];
    std::cin >> n >> m;
    std::set<int> p[3001];
    for (int i = 0; i < m; ++i) {
        int b1, b2;
        std::cin >> b1 >> b2;
        p[b1].insert(b2);
        p[b2].insert(b1);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> rm[i];
        o[rm[i]] = n - i;
    }

    int c = 0, id[3001];
    bool r[3001];
    for (int i = 0; i <= n; ++i)
        id[i] = i;
    for (int i = n - 1; i >= 0; --i) {
        c++;
        for (std::set<int>::iterator j = p[rm[i]].begin(); j != p[rm[i]].end(); ++j)
            if (o[*j] < o[rm[i]])
                if (unite(id, rm[i], *j))
                    c--;
        r[i] = c == 1;
    }
    for (int i = 0; i < n; ++i)
        std::cout << (r[i] ? "YES" : "NO") << std::endl;
    return 0;
}
