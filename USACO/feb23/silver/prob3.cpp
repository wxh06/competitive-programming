#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

struct Flight {
    int to, leave, arrive;
    bool visited;
};

bool comp(Flight a, Flight b) {
    return a.leave > b.leave;
}

int main() {
    int a[200001], m, n, earliest[200001];
    std::cin >> n >> m;
    std::vector<Flight> to[200001];
    for (int i = 0; i < m; ++i) {
        int ci, ri, di, si;
        std::cin >> ci >> ri >> di >> si;
        to[ci].push_back((Flight){di, ri, si, false});
    }
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::queue<int> airports;
    std::fill(earliest + 1, earliest + n + 1, -1);
    airports.push(1);
    earliest[1] = -a[1];
    for (int i = 1; i <= n; ++i)
        std::sort(to[i].begin(), to[i].end(), comp);
    while (!airports.empty()) {
        int airport = airports.front();
        airports.pop();
        int l = 0, r = to[airport].size();
        while (l < r) {
            int m = (l + r) / 2;
            if (!to[airport][m].visited)
                r = m;
            else
                l = m + 1;
        }
        for (int i = l; i < to[airport].size(); ++i)
            if (!to[airport][i].visited && to[airport][i].leave >= earliest[airport] + a[airport]) {
                to[airport][i].visited = true;
                earliest[to[airport][i].to] = earliest[to[airport][i].to] == -1 ? to[airport][i].arrive : std::min(earliest[to[airport][i].to], to[airport][i].arrive);
                airports.push(to[airport][i].to);
            } else break;
    }
    std::cout << 0;
    for (int i = 2; i <= n; ++i)
        std::cout << std::endl << earliest[i];
    return 0;
}
