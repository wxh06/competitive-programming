i#include <bits/stdc++.h>

int main() {
	freopen("souvenir.in", "r", stdin);
	freopen("souvenir.out", "w", stdout);
	int m, n, t, p[101][101];
	std::cin >> t >> n >> m;
	for (int i = 1; i <= t; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> p[i][j];
	if (n == 1) {
		int c = 0;
		for (int i = 1; i < t; i++) {
			m += c * p[i][1];
			c = 0;
			if (p[i + 1][1] > p[i][1]) {
				c = m / p[i][1];
				m -= c * p[i][1];
			}
		}
		m += c * p[t][1];
	} else if (t == 2) {  // TODO
		int r = 0;
		for (int i = 1; i <= n; i++)
			r = std::max(m + m / p[1][i] * (p[2][i] - p[1][i]), r);
		m = r;
	}
	std::cout << m;
	return 0;
}
