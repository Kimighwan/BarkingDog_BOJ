#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001], dist[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int result = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push({ i, j });
			if (map[i][j] == 0)
				dist[i][j] = -1;
		}
	}
	

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == -1 || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}

			result = max(result, dist[i][j]);
		}
	}
	cout << result;
}