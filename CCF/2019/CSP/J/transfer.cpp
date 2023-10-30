#include <bits/stdc++.h>

int main() {
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	size_t l = 0, m[2] = {}, n, r = 0;
	std::cin >> n;
	int p[2][100000], t[2][100000];
	for (size_t i = 0; i < n; i++) {
		bool f;
		std::cin >> f;
		std::cin >> p[f][m[f]] >> t[f][m[f]];
		m[f]++;
	}
	for (size_t i = 0; i < m[0]; i++)
		r += p[0][i];
	bool u[100000] = {};
	for (size_t i = 0, j; i < m[1]; i++) {
//		j = l = std::lower_bound(t[0] + l, t[0] + m[0], t[1][i] - 45) - t[0];
		while (t[0][l] < t[1][i] - 45 && l < m[0])
			l++;
		j = l;
		while (j < m[0] && t[0][j] < t[1][i] && (u[j] || p[0][j] < p[1][i]))
			j++;
		if (t[0][j] > t[1][i] || u[j] || p[0][j] < p[1][i])
			r += p[1][i];
		else
			u[j] = true;
	}
	std::cout << r;
	return 0;
}
