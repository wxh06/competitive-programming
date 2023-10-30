#include <bits/stdc++.h>


unsigned long long f(unsigned long long n, unsigned long long k, bool r=false) {
//	printf("%llu %llu ", n, k);
//	std::cout << r << std::endl;
	if (n == 1)
		return r ? !k : k;
	if (k < ((unsigned long long)1 << (n - 1)))
		return f(n - 1, k, false) + ((unsigned long long)1 << (n - 1)) * r;
	else
		return f(n - 1, k - ((unsigned long long)1 << (n - 1)), true) + ((unsigned long long)1 << (n - 1)) * !r;
}

int main() {
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	unsigned long long _n = 1, k, n;
	std::cin >> n >> k;
	while (((unsigned long long)1 << _n) <= k)
		_n++;
	unsigned long long r = f(_n, k); 
	for (unsigned long long i = (unsigned long long)1 << (n - 1); i > 0; i >>= 1)
		std::cout << (bool)(r & i);
	return 0;
}
