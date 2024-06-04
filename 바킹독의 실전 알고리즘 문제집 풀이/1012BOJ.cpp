#include <iostream>
#include <queue>
using namespace std;

int map[51][51];
bool visited[51][51];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n, k;
		int x, y;
		int result = 0;
		cin >> m >> n >> k;
		queue<pair<int, int>> q;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !visited[i][j])
				{
					result++;
					visited[i][j] = true;
					q.push({ i, j });
					while (!q.empty())
					{
						auto cur = q.front(); q.pop();
						for (int i = 0; i < 4; i++)
						{
							int nx = cur.first + dx[i];
							int ny = cur.second + dy[i];
							if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
							if (map[nx][ny] != 1 || visited[nx][ny]) continue;
							visited[nx][ny] = true;
							q.push({ nx, ny });
						}
					}
				}
			}
		}

		cout << result << '\n';

		for (int i = 0; i < n; i++) {
			fill(map[i], map[i] + m, 0);
			fill(visited[i], visited[i] + m, false);
		}
	}
}