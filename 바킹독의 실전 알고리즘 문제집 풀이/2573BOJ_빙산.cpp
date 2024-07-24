#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
bool visit[301][301];
int map[301][301];
int tmp[301][301];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1 , 0,0 };

void check(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
				if(!visit[nx][ny] && map[nx][ny] != 0)
				{
					visit[nx][ny] = true;
					q.push({ nx, ny });
				}
		}
	}
}

void Melt() {
	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0) continue;
			int cnt = 0;
			for (int d = 0; d < 4; d++)
			{
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (map[nx][ny] == 0) cnt++;
			}
			int val = map[i][j] - cnt;
			if (val > 0) tmp[i][j] = val;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int year = 0;
	while (1) {
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visit[i][j] && map[i][j] != 0) 
				{
					check(i, j);
					cnt++;
				}
			}
		}

		if (cnt == 0) {
			cout << 0;
			return 0;
		}
		else if (cnt >= 2)
		{
			cout << year;
			return 0;
		}

		year++;
		Melt();
		memset(visit, false, sizeof(visit));
	}
}