/*
ID: wangxin22
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	map<string, int> dict;
	unsigned np;
	cin >> np;
	string name, names[10];
	for (int i = 0; i < np; ++i)
	{
		cin >> name;
		names[i] = name;
		dict[name] = 0;
	}
	unsigned p, m;
	while (cin >> name)
	{
		cin >> p >> m;
		if (m)
		{
			p -= p % m;
			dict[name] -= p;
			for (int i = 0; i < m; ++i)
			{
				cin >> name;
				dict[name] += p / m;
			}
		}
	}
	for (int i = 0; i < np; ++i)
		cout << names[i] << ' ' << dict[names[i]] << endl;
	return 0;
}
