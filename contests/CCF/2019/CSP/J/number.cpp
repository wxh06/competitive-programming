#include <bits/stdc++.h>

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	size_t c = 0;
	std::string s;
	std::cin >> s;
	for (int i = 0; i < 8; i++)
		if (s[i] =='1')
			c++;
	std::cout << c;
	return 0;
}
