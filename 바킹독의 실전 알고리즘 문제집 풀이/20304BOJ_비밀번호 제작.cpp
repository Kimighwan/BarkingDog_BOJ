#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dist[1'000'010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, tmp, next;

	cin >> n;
	cin >> m;
	vector<int> start{};
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		start.push_back(tmp);
	}

	fill(dist, dist + n + 2, -1);

	queue<int> q{};
	for (auto& item : start) {
		dist[item] = 0;
		q.push(item);
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int k{}; k < 31; ++k) {
			if (cur & (1 << k))
				next = cur & ~(1 << k);
			else
				next = cur | (1 << k);
			if (next > n) continue;
			if (dist[next] >= 0) continue;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}

	int ans = 0;
	for (int i{}; i <= n; ++i)
		ans = max(ans, dist[i]);

	cout << ans;
}