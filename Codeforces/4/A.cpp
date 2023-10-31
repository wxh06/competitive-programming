#include <iostream>
using namespace std;
 
int main() {
	unsigned short n;
	cin >> n;
	cout << (!(n % 2) && n != 2 ? "YES" : "NO");
	return 0;
}
