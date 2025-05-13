#include <iostream>
#include <vector>
using namespace std;

vector<bool> ans(1'000'001, true);

void F(int n)
{
	ans[1] = false;

	for (int i = 2; i * i <= n; i++)
	{
		if (!ans[i]) continue;
		for (int j = i * i; j <= n; j += i)
			ans[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n; 
	cin >> m >> n;
	
	F(n);

	for (int i = m; i <= n; i++)
		if (ans[i]) cout << i << "\n";
}