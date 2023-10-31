#include <iostream>
using namespace std;
int main() {
	unsigned x, y, sx, sy, tx, ty;
	char cx, cy;
	cin >> cx; sx = cx - 'a' + 1;
	cin >> sy;
	cin >> cx; tx = cx - 'a' + 1;
	cin >> ty;
	x = max(sx, tx) - min(sx, tx);
	y = max(sy, ty) - min(sy, ty);
	cout << max(x, y) << endl;
	cx = sx < tx ? 'R' : 'L';
	cy = sy < ty ? 'U' : 'D';
	for (unsigned i = 0; i < min(x, y); ++i)
		cout << cx << cy << endl;
	for (unsigned i = min(x, y); i < max(x, y); ++i)
		cout << (x > y ? cx : cy) << endl;
	return 0;
}
