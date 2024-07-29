#include <iostream>
#include <queue>
using namespace std;

int sis, bro;
queue<int> q;
int dist[200'002];
int prePos[200'002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> sis >> bro;
	dist[sis] = 1;
	prePos[sis] = sis;
	q.push(sis);

	while (!dist[bro])
	{
		int cur = q.front(); q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 || nxt > 200'000) continue;
			if (dist[nxt]) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
			prePos[nxt] = cur;
		}
	}
	cout << dist[bro] - 1 << '\n';
	deque<int> dq = { bro };
	while (dq.front() != sis) dq.push_front(prePos[dq.front()]);
	for (auto out : dq)
		cout << out << " ";
}