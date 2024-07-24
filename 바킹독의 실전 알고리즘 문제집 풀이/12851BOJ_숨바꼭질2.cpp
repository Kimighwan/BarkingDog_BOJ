#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
int dist[100'001];
int cnt[100'001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (n == k)
	{
		cout << 0 << '\n' << 1;
		return 0;
	}


	memset(dist, -1, sizeof(dist));
	dist[n] = 0;
	cnt[n] = 1;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt > 100'000 || nxt < 0) continue;
			if (dist[nxt] != -1)
			{
				if(dist[nxt] == dist[cur] + 1)
					cnt[nxt] += cnt[cur];
			}
			else {
				dist[nxt] = dist[cur] + 1;
				cnt[nxt] = cnt[cur];
				q.push(nxt);
			}
		}
	}
	cout << dist[k] << '\n' << cnt[k];
}