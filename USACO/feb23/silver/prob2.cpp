#include <cmath>
#include <algorithm>
#include <iostream>

struct Grazing {
    long long x, y, t;
};

bool comp(Grazing a, Grazing b) {
    return a.t < b.t;
}

int main() {
    long long g, n, t[100000], c = 0;
    std::cin >> g >> n;
    Grazing grazings[100000];
    for (long long i = 0; i < g; ++i)
        std::cin >> grazings[i].x >> grazings[i].y >> grazings[i].t;
    std::sort(grazings, grazings + g, comp);
    for (long long i = 0; i < g; ++i)
        t[i] = grazings[i].t;
    for (long long i = 0; i < n; ++i) {
        long long xi, yi, ti;
        std::cin >> xi >> yi >> ti;
        long long ub = std::lower_bound(t, t + g, ti) - t;
        if ((grazings[ub].t == ti && grazings[ub].x == xi && grazings[ub].y == yi) ||
            ((ub == 0 || (grazings[ub - 1].x - xi) * (grazings[ub - 1].x - xi) + (grazings[ub - 1].y - yi) * (grazings[ub - 1].y - yi) <= (ti - t[ub - 1]) * (ti - t[ub - 1])) &&
             (ub == g || (xi - grazings[ub].x) * (xi - grazings[ub].x) + (yi - grazings[ub].y) * (yi - grazings[ub].y) <= (t[ub] - ti) * (t[ub] - ti))))
            c++;
    }
    std::cout << n - c;
    return 0;
}
