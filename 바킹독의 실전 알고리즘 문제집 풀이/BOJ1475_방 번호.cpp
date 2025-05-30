#include <iostream>
using namespace std;

int num[10];

int main() {
	int n; cin >> n;

	while (n)
	{
		num[n % 10]++;
		n /= 10;
	}

	int max = 0;

	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9) continue;
		if (num[i] > max) max = num[i];
	}

	int sum = num[6] + num[9];

	if (sum % 2 == 0) 
	{
		sum /= 2;
	}
	else {
		sum /= 2;
		sum++;
	}

	if (max < sum) max = sum;

	cout << max;
}