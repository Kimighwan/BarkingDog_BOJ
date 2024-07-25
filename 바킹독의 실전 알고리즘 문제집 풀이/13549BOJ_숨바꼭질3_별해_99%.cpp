#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, k;
int dist[200'002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	fill(dist, dist + 200'000, -1);
	deque<int> dq;
	dq.push_back(n);
	dist[n] = 0;

	while (!dq.empty())
	{
		int cur = dq.front();
		dq.pop_front();

		if (cur * 2 < 200'000 && dist[cur * 2] == -1)
		{
			dist[cur * 2] = dist[cur];
			dq.push_front(cur * 2);
		}

		for (int nxt : {cur + 1, cur - 1})
		{
			if (nxt < 0 || nxt >= 200'000 || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			dq.push_back(nxt);
		}
	}
	cout << dist[k];
}