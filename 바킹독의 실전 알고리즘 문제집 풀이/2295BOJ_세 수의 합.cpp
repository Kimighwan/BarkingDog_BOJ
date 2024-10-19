#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
vector<int> two;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n); // 정렬할 필요는 없지만 발견하자 마자 바로 끝낼 수 있음

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			two.push_back(arr[i] + arr[j]);

	sort(two.begin(), two.end());

	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < n; j++) {
			if (binary_search(two.begin(), two.end(), arr[i] - arr[j])){
				cout << arr[i];
				return 0;
			}
		}
}