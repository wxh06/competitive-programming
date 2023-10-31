#include <sstream>
#include <iostream>
using namespace std;
 
string ToNumberSystem26(int n) {
	string s;
	while (n > 0){
		unsigned m = n % 26;
		if (m == 0)
			m = 26;
		s = (char)(m + 64) + s;
		n = (n - m) / 26;
	}
	return s;
}
 
unsigned FromNumberSystem26(string s) {
	if (s.empty())
		return 0;
	unsigned n = 0;
	for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 26){
		if (s[i] < 'A' || s[i] > 'Z')
			return 0;
		n += ((unsigned)s[i] - 64) * j;
	}
	return n;
}
 
int main() {
	unsigned n;
	cin >> n;
	for (unsigned i = 0; i < n; ++i) {
		string s;
		cin >> s;
		stringstream ss;
		if (s.find('C') != string::npos && s.find('C') > 1 && s[s.find('C') - 1] >= '0' && s[s.find('C') - 1] <= '9') {
			unsigned x, y;
			ss << s.substr(1, s.find('C') - 1) << " " << s.substr(s.find('C') + 1);
			ss >> x >> y;
			cout << ToNumberSystem26(y) << x << endl;
		}
		else {
			unsigned j;
			for (j = 0; j < s.length(); ++j)
				if (s[j] >= '0' && s[j] <= '9')
					break;
			unsigned x;
			ss << s.substr(j);
			ss >> x;
			cout << "R" << x << "C" << FromNumberSystem26(s.substr(0, j)) << endl;
		}
	}
	return 0;
}
