#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, m;
deque<int> Q;
int result = 0, cnt = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		Q.push_back(i);

	while (m--)
	{
		int x; cin >> x;
		int index = find(Q.begin(), Q.end(), x) - Q.begin();

		while (Q.front() != x)
		{
			if (((int)Q.size()) / 2 >= index)
			{
				Q.push_back(Q.front());
				Q.pop_front();
			}
			else
			{
				Q.push_front(Q.back());
				Q.pop_back();
			}
			result++;
		}

		Q.pop_front();
	}

	cout << result;
}