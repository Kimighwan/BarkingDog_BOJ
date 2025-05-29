#include <iostream>
#include <string>
using namespace std;

int a, b, c;
int num[10];

int main() {
	cin >> a >> b >> c;

	int mul = a * b * c;

	while (mul)
	{
		num[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << num[i] << "\n";
}