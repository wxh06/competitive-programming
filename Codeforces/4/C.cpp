#include <map>
#include <iostream>
using namespace std;
 
int main() {
	map<string, unsigned> dict;
	map<string, unsigned>::iterator iter;
	unsigned n;
	cin >> n;
	for (unsigned i = 0; i < n; ++i) {
		string name;
		cin >> name;
		if (dict.count(name)) {
			cout << name + to_string(dict[name]) << endl;
			dict[name]++;
		}
		else {
			dict[name] = 1;
			cout << "OK" << endl;
		}
	}
	return 0;
}
