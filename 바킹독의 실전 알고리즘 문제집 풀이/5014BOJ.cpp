#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int dist[1'000'001];
int cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> F >> S >> G >> U >> D;
	fill(dist + 1, dist + 1 + F, -1);
	dist[S] = 0;
	queue<int> q;
	q.push(S);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto nxt : {cur + U, cur - D})
		{
			if (nxt <= 0 || nxt > F || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	if (dist[G] != -1) cout << dist[G];
	else cout << "use the stairs";
}