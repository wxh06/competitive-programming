#include <set>
#include <iostream>

typedef struct {
    int value, l, r, parent, depth;
} Node;

int main() {
    char s[201];
    std::cin >> s;

    int n;
    Node nodes[200];
    for (n = 0; s[n]; ++n) {
        nodes[n].value = s[n] - '0';
        nodes[n].l = 0;
        nodes[n].r = 0;
    }
    nodes[0].depth = 0;
    for (int i = 1; i < n; ++i) {
        int parent = 0, depth = nodes[0].depth + 1;
        for (;; ++depth) {
            if (nodes[i].value <= nodes[parent].value) {
                if (!nodes[parent].l) {
                    nodes[parent].l = i;
                    nodes[i].parent = parent;
                    nodes[i].depth = depth;
                    break;
                }
                parent = nodes[parent].l;
            } else {
                if (!nodes[parent].r) {
                    nodes[parent].r = i;
                    nodes[i].parent = parent;
                    nodes[i].depth = depth;
                    break;
                }
                parent = nodes[parent].r;
            }
        }
    }

    std::set<int> p;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int current_i = i, current_j = j, min_depth = nodes[i].depth, sum = 0;
            if (nodes[i].depth > nodes[j].depth) {
                min_depth = nodes[j].depth;
                while (nodes[current_i].depth > min_depth) {
                    sum += nodes[current_i].value;
                    current_i = nodes[current_i].parent;
                }
            } else if (nodes[i].depth < nodes[j].depth) {
                while (nodes[current_j].depth > min_depth) {
                    sum += nodes[current_j].value;
                    current_j = nodes[current_j].parent;
                }
            }
            while (current_i != current_j) {
                sum += nodes[current_i].value;
                current_i = nodes[current_i].parent;
                sum += nodes[current_j].value;
                current_j = nodes[current_j].parent;
            }
            sum += nodes[current_i].value;
            p.insert(sum);
        }
    }
    std::cout << p.size();
    return 0;
}
