#include <bits/stdc++.h>


const long long p = 998244353;
long long a[100][2000], c[2000], m, n;
bool u[100][2000], f;

long long dfs(long long x, long long y, long long k = 1) {
	// std::cout << "Called: " << x <<  ", " << y << ", " << k << std::endl;
	u[x][y] = true;
	c[y]++;
	long long r = 0;
	for (long long i = 1; x + i < n; i++) {
		for (long long j = 0; j < m; j++)
			if (a[x + i][j]) {
				r += dfs(x + i, j, k + 1);
				if (!f)
					r %= p;
			}
	}
	// std::cout << k << ' ' << (k && *std::max_element(c, c + m) <= k / 2.0) << std::endl;
	// for (long long i = 0; i < n; std::cout << std::endl, i++)
	// 	for (long long j = 0; j < m; j++)
	// 		std::cout << ' ' << u[i][j];
	r += k && *std::max_element(c, c + m) <= k / 2.0;
	r *= a[x][y];
	u[x][y] = false;
	c[y]--;
	// std::cout << "Returned" << std::endl;
	return r;
}

int main() {
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	std::cin >> n >> m;
	for (long long i = 0; i < n; i++)
		for (long long j = 0; j < m; j++) {
			std::cin >> a[i][j];
			if (a[i][j] >= 2)
				f = true;
		}
	long long r = 0;
	for (long long i = 0; i <= n; i++) {
		for (long long j = 0; j < m; j++)
			if (a[i][j]) {
				r += dfs(i, j);
				r %= p;
			}
	}
	std::cout << r;
	return 0;
}
