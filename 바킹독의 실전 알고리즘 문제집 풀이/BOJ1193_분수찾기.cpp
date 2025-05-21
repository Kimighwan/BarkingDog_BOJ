#include <iostream>
using namespace std;

int x;

int main() {
	cin >> x;

	int i = 1;
	while (x > i)
	{
		x -= i;
		i++;
	}

	// i 군의 x 번째 분수 출력
	int num = x;
	int q = i - x + 1;
	
	if (i % 2) // 홀수는 홀수/1
	{
		cout << q << "/" << num;
	}
	else // 짝수는 1/짝수
	{
		cout << num << "/" << q;
	}
}