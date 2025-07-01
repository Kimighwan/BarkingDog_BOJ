#include <iostream>
#include <stack>
using namespace std;

int n;
stack <pair<int, int>> S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	S.push(make_pair(100000001, 0));

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;

		while (S.top().first < x)
			S.pop();
		cout << S.top().second << " ";
		S.push({ x, i });
	}
}