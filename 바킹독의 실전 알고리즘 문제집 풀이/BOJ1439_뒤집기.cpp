#include <iostream>
#include <string>
using namespace std;

string arr;
int cnt[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> arr;
	for (int i = 0; i < int(arr.size()); i++)
	{
		if (i == int(arr.size()) - 1)
		{
			cnt[int(arr[i]) - 48]++;
			break;
		}

		if (arr[i] != arr[i + 1])
			cnt[int(arr[i]) - 48]++;
	}

	int ans = cnt[0] < cnt[1] ? cnt[0] : cnt[1];

	cout << ans;
}