#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	deque<int> dq;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	int result = 0;
	while (m--)
	{
		int x;
		cin >> x;
		int index = find(dq.begin(), dq.end(), x) - dq.begin();
		while (dq.front() != x)
		{
			if (index > (int) - index)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			else
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			result++;
		}
		dq.pop_front();
	}
	cout << result;
}