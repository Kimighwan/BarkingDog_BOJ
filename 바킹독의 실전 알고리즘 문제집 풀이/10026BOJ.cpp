#include <iostream>
#include <queue>
using namespace std;

int n;
string map[101];
bool visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] || map[x][y] != map[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int Area() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j])
			{
				cnt++;
				BFS(i, j);
			}
		}
	}
	return cnt;
}

int main() { // 빨강과 초록색이 똑같은 색
	ios::ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int n_color = Area();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G')
				map[i][j] = 'R';
			visited[i][j] = false;
		}
	}

	int is_color = Area();

	cout << n_color << " " << is_color;
}