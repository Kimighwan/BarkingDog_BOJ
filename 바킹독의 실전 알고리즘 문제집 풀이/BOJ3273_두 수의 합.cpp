#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());

	auto start = arr.begin();
	auto end = arr.end() - 1;

	int cnt = 0;

	int x; cin >> x;

	while (start < end)
	{
		if (*start + *end == x)
		{
			cnt++;
			start++;
			end--;
		}
		else if (*start + *end > x) end--;
		else start++;
	}

	cout << cnt;
}


//int a[1000001] = {};
//// 각 자연수의 존재 여부를 저장하는 배열, 아래에서 x-a[i]가 1000000보다 큰 경우를 예외처리하기 싫어서 그냥 배열을 최대 200만으로 잡음
//bool occur[2000001];
//int n, x;
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int ans = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	cin >> x;
//
//	for (int i = 0; i < n; i++) {
//		// x-a[i]가 존재하는지 확인
//		if (x - a[i] > 0 && occur[x - a[i]]) ans++;
//		occur[a[i]] = true;
//	}
//	cout << ans;
//}
//
///*
//공간복잡도 O(2000000), 시간복잡도 O(n)에 풀이가 가능. 만약 입력 형식에서
//x가 a 배열보다 먼저 주어졌다면 int a[] 배열은 필요가 없었음.
//*/

//////////////////////////////////////////////////////////////////////////////////////

//// 각 자연수의 존재 여부를 저장하는 배열, 배열의 크기를 200만으로 두어
//// 25번째 줄에서 x-i의 범위를 별도로 체크하지 않아도 되게끔 했다.
//int a[2000001] = {};
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, t, x, ans = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		cin >> t;
//		a[t]++;
//	}
//
//	cin >> x;
//	for (int i = 1; i < (x + 1) / 2; ++i) {
//		// 합이 x가 되는 서로 다른 자연수 (i,x-i)가 존재할 경우
//		if (a[i] == 1 && a[x - i] == 1) ans++;
//	}
//	cout << ans;
//}
//
///*
//x가 짝수일 때에는 (x/2 - 1)까지, 홀수일 때에는 (x-1)/2까지 탐색할 수 있도록 하기 위해서
//i < (x+1)/2로 뒀음. 직접 x가 10일 때 / 11일 때를 생각해보면 이해 가능
//이 코드는 O(n+x)에 동작, x가 최대 200만이므로 통과에는 문제가 없으나 O(n)에 비해서는 느림.
//*/