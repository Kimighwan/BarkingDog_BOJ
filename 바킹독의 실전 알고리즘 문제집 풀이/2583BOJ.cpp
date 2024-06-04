#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, k;
int map[101][101];
bool visit[101][101];
int dx[4] = { 0 , 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;
	while (k--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				map[i][j] = 1;
	}

	int cnt = 0;
	vector<int> ans;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (map[i][j] == 1 || visit[i][j])
				continue;

			queue<pair<int, int>> q;
			visit[i][j] = true;
			q.push({ i, j });
			cnt++;
			int area = 1;

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (map[nx][ny] == 1 || visit[nx][ny])
						continue;
					q.push({ nx, ny });
					visit[nx][ny] = true;
					area++;
				}
			}
			ans.push_back(area);
		}
	}

	sort(ans.begin(), ans.end());

	cout << cnt << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}