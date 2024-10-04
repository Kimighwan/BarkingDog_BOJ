#include <iostream>
#include <vector>
using namespace std;

int n, m, map[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 남쪽, 동쪽, 북쪽, 서쪽 순서
vector<pair<int, int>> cctvPos;
int ans = 100;

void Sol(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		x = nx;
		y = ny;
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) return;
		if (map[nx][ny] == '6') return;
		if (map[nx][ny] != 0) continue;
		map[nx][ny] == -1;
	}
}

void DFS(int idx) {
	if (idx == cctvPos.size()) // 여기서 사각 지대의 최소인지 체크
	{
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == -1) cnt++;
			}
		}

		ans = min(ans, cnt);
		return;
	}

	int x = cctvPos[idx].first;
	int y = cctvPos[idx].second;
	int tmp[9][9];

	for (int dir = 0; dir < 4; dir++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp[i][j] = map[i][j];

		if (map[x][y] == 1)
			Sol(x, y, dir);
		else if (map[x][y] == 2)
		{
			Sol(x, y, dir);
			Sol(x, y, dir + 2);
		}
		else if (map[x][y] == 3)
		{
			Sol(x, y, dir);
			Sol(x, y, dir + 1);
		}
		else if (map[x][y] == 4)
		{
			Sol(x, y, dir);
			Sol(x, y, dir + 1);
			Sol(x, y, dir + 2);
		}
		else if (map[x][y] == 4)
		{
			Sol(x, y, dir);
			Sol(x, y, dir + 1);
			Sol(x, y, dir + 2);
			Sol(x, y, dir + 3);
		}
	}

	DFS(idx + 1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = tmp[i][j];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != '6' && map[i][j] != '0') cctvPos.push_back({ i, j });
		}
	}

	DFS(0);
}