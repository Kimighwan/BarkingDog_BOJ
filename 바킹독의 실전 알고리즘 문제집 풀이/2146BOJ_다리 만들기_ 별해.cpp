#include <iostream>
#include <queue>
using namespace std;

int map[101][101]; // 0 ¹Ù´Ù // 1 À°Áö
int dist[101][101];
bool visit[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, ind = 1;
int result = 999999;

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
				queue <pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = true;
				while (!q.empty())
				{
					int curx = q.front().first;
					int cury = q.front().second;
					q.pop();
					map[curx][cury] = ind;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = curx + dx[dir];
						int ny = cury + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (visit[nx][ny] || map[nx][ny] == 0) continue;
						visit[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
				ind++;
			}
		}

	queue <pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0) continue;
			q.push({ i, j });
		}

	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curx + dx[dir];
			int ny = cury + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[curx][cury] == map[nx][ny]) continue;
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = map[curx][cury];
				dist[nx][ny] = dist[curx][cury] + 1;
				q.push({ nx, ny });
			}
			else
				result = min(result, dist[nx][ny] + dist[curx][cury]);
		}
	}

	cout << result;
}