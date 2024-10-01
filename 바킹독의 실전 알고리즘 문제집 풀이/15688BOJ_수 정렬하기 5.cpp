#include <iostream>
using namespace std;

int n, idx;
int arr[2'000'002] = {}; // 0 ~ 1'000'000 원소

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> idx;
		arr[idx + 1'000'000]++;
	}


	for (int i = 0; i <= 2'000'000; i++)
	{
		while (arr[i]--)
		{
			cout << i - 1'000'000 << '\n';
		}
	}

}