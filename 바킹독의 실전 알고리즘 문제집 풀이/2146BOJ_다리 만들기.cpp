#include <iostream>
#include <queue>
using namespace std;

int map[101][101]; // 0 �ٴ� // 1 ����
int dist[101][101];
bool visit[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, cnt = 0;
int result = 999999;
queue <pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && !visit[i][j])
			{
				cnt++;
				visit[i][j] = true;
				map[i][j] = cnt;
				q.push({ i,j });
				while (!q.empty())
				{
					int curx = q.front().first;
					int cury = q.front().second;
					q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = curx + dx[dir];
						int ny = cury + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n ) continue;
						if (visit[nx][ny] || map[nx][ny] == 0) continue;
						map[nx][ny] = cnt;
						visit[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != 0)
			{
				q.push({ i,j });
				bool escape = false;
				while (!q.empty() && !escape)
				{
					int curx = q.front().first;
					int cury = q.front().second;
					q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = curx + dx[dir];
						int ny = cury + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (dist[nx][ny] > 0 || map[i][j] == map[nx][ny]) continue;
						if (map[i][j] != map[nx][ny] && map[nx][ny] != 0)
						{
							result = min(result, dist[curx][cury]);
							while (!q.empty()) q.pop();
							escape = true;
							break;
						}
						dist[nx][ny] = dist[curx][cury] + 1;
						q.push({ nx, ny });
					}
				}
				for (int i = 0; i < n; i++)
					fill(dist[i], dist[i] + n, 0);
			}
		}
	cout << result;
}