// (결정 문제) ==> 랜선의 길이가 X일 때 랜선이 N개 이상인가 ? 아닌가 ?
#include <iostream>
using namespace std;

int k, n;
int arr[10001];

bool F(long long x) {
	long long cur = 0;
	for (int i = 0; i < k; i++) cur += arr[i] / x;
	return cur >= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];

	long long s = 1;
	long long e = 0x7fffffff;
	
	while (s < e)
	{
		long long mid = (s + e + 1) / 2;
		if (F(mid)) s = mid;
		else e = mid - 1;
	}
	cout << s;
}