#include <iostream>
#include <queue>
using namespace std;
int board[502][502];
int n, m;
bool visited[502][502];

int dx[4] = { 0 , 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int mx = 0, cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] || board[i][j] == 0) continue;
			queue<pair<int, int>> q;
			cnt++;
			visited[i][j] = true;
			q.push({ i, j });
			int area = 0;

			while (!q.empty())
			{
				area++;
				pair<int, int> cur = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 0 || visited[nx][ny]) continue;
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}

			mx = max(mx, area);
		}
	}
	cout << cnt << '\n' << mx;
}