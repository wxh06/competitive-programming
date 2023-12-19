#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

constexpr int N = 200001;

struct Road {
    int to;
    long long label;

    bool operator<(const Road &rhs) const {
        return this->label < rhs.label;
    }
};

struct Trip {
    int len;
    long long sum;
} trip[N];

std::vector<Road> from[N];

void search(int i) {
    if (trip[i].len) return;

    int max_len = -1;
    for (Road r: from[i]) {
        search(r.to);
        max_len = std::max(trip[r.to].len, max_len);
    }
    if (max_len < 0)
        return;

    std::deque<Road> next;
    for (Road r: from[i])
        if (trip[r.to].len == max_len)
            next.push_back(r);

    for (int j = 0; j <= max_len; ++j) {
        size_t s = next.size();
        if (s == 1) {
            trip[i].len += trip[next.back().to].len + 1;
            trip[i].sum += trip[next.back().to].sum + next.back().label;
            break;
        }

        long long min_label = std::min_element(next.begin(), next.end())->label;
        while (s--) {
            Road t = next.front();
            next.pop_front();
            if (t.label == min_label)
                for (Road r: from[t.to])
                    next.push_back(r);
        }
        trip[i].len++;
        trip[i].sum += min_label;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long l;
        scanf("\n%d %d %lld", &a, &b, &l);
        from[a].push_back(Road{b, l});
    }

    for (int i = 1; i <= n; ++i) {
        search(i);
        printf("%d %lld\n", trip[i].len, trip[i].sum);
    }

    return 0;
}
