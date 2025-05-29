// 1. 30초 마다 10원
// 2. 60초 마다 15원
#include <iostream>
using namespace std;

int n, y = 0, m = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;

		x += 1;

		y += (x / 30) * 10;
		if (x % 30) y += 10;

		m += (x / 60) * 15;
		if (x % 60) m += 15;
	}

	if (y > m)
		cout << "M " << m;
	else if(y < m)
		cout << "Y " << y;
	else
		cout << "Y M " << m;
}