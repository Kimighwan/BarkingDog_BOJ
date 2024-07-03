#include <iostream>
#include <queue>
using namespace std;

int n;
int map[101][101];
bool visit[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int mx = 0, safe = 0;
	for(int i = 0 ; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			mx = max(mx, map[i][j]);
		}

	for (int limit = 0; limit <= mx; limit++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			fill(visit[i], visit[i] + n, false);

		queue<pair<int, int>> q;
		for(int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
			{
				if (visit[j][k] || map[j][k] <= limit) continue;
				q.push({ j, k });
				cnt++;
				while (!q.empty())
				{
					auto cur = q.front(); q.pop();
					for (int d = 0; d < 4; d++)
					{
						int nx = cur.first + dx[d];
						int ny = cur.second + dy[d];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (visit[nx][ny] || map[nx][ny] <= limit) continue;
						q.push({ nx, ny });
						visit[nx][ny] = true;
					}
				}
			}
		safe = max(cnt, safe);
	}
	cout << safe;
}