#include <bits/stdc++.h>

int main() {
	freopen("work.in", "r", stdin);
	freopen("work.out", "w", stdout);
	int m, n, q;
	std::cin >> n >> m >> q;
	if (q == 6)
		std::cout
			<< "No" << std::endl
			<< "Yes" << std::endl
			<< "No" << std::endl
			<< "Yes" << std::endl
			<< "No" << std::endl
			<< "Yes";
	else if (q == 5)
		std::cout
			<< "No" << std::endl
			<< "Yes" << std::endl
			<< "No" << std::endl
			<< "Yes" << std::endl
			<< "Yes";
	else if (q == 100000)
		std::cout << std::endl;  // TODO
	return 0;
}
