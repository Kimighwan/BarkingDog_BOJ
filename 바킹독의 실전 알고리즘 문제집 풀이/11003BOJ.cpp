#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	deque<pair<int, int>> d;
	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (!d.empty() && d.back().second >= num)
			d.pop_back();

		d.push_back({ i, num });

		if (d.front().first <= i - l) 
			d.pop_front();

		cout << d.front().second << " ";
	}
}