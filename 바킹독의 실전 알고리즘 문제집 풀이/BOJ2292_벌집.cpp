#include <iostream>
using namespace std;

long long n;

int main() {
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}
	
	n -= 1;

	for (int i = 2; i <= 1000000; i++)
	{
		n -= 6 * (i - 1);
		if (n <= 0)
		{
			cout << i;
			return 0;
		}
	}
}