#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
int dist[200'002];
queue<int> q;

void Teleport(int num) {
	if (num == 0) return;
	int tmp = num;
	while (tmp < 100'001 && dist[k] == -1) 
	{
		if (dist[tmp] == -1) 
		{
			dist[tmp] = dist[num];
			q.push(tmp);
			if (tmp == k) return;
		}
		tmp <<= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (n == k)
	{
		cout << 0;
		return 0;
	}


	memset(dist, -1, sizeof(dist));
	dist[n] = 0;
	q.push(n);
	Teleport(n);

	while (dist[k] == -1)
	{
		int cur = q.front(); q.pop();

		for (int nxt : {cur - 1, cur + 1})
		{
			if (nxt > 100'000 || nxt < 0 || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
			Teleport(nxt);
		}
	}
	cout << dist[k];
}