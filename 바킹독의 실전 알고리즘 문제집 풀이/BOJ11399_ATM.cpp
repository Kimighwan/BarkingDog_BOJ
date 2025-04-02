#include <iostream>
#include <algorithm>
using namespace std;

int n, p[1001], result = 0;
int personal[1001], tmp = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i];

	sort(p, p + n);

	for (int i = 0; i < n; i++)
	{
		result += p[i] + tmp;
		tmp = p[i] + tmp;
	}

	cout << result;
}