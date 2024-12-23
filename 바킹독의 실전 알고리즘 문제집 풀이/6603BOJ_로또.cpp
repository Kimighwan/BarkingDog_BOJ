#include <iostream>
using namespace std;

int k, s[13], ans[7];

void F(int cur) {
	if (cur == 6) {
		for (int i = 0; i < 6; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = ans[cur - 1];
	for (int i = 0; i < k; i++)
	{
		if (tmp < s[i])
		{
			ans[cur] = s[i];
			F(cur + 1);
		}
	}
}

int main() {
	while (1)
	{
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++)
			cin >> s[i];

		F(0);
		cout << "\n";
	}
}