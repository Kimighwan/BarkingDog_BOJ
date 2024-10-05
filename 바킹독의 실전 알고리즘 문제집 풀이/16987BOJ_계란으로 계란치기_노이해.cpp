#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1 , 0, -1, 0 };
int map[10][10];
vector<pair<int, int>> cctv;
int ans = 100000;

void Solve(int x, int y, int dir) {
	dir %= 4;
	while (1) 
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		x = nx;
		y = ny;
		if (x < 0 || y < 0 || x >= n || y >= m) return;
		if (map[x][y] == 6)	return;
		if (map[x][y] != 0) continue;
		map[x][y] = 7;
	}
}

void DFS(int index) {
	if (index == cctv.size()) 
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 0) cnt++;
		ans = min(ans, cnt);
		return;
	}

	int x = cctv[index].first;
	int y = cctv[index].second;

	int tmp[10][10];

	for (int dir = 0; dir < 4; dir++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp[i][j] = map[i][j];

		if (map[x][y] == 1)
			Solve(x, y, dir);
		else if (map[x][y] == 2) {
			Solve(x, y, dir);
			Solve(x, y, dir + 2);
		}
		else if (map[x][y] == 3) {
			Solve(x, y, dir);
			Solve(x, y, dir + 1);
		}
		else if (map[x][y] == 4) {
			Solve(x, y, dir);
			Solve(x, y, dir + 1);
			Solve(x, y, dir + 2);
		}
		else if (map[x][y] == 5) {
			Solve(x, y, dir);
			Solve(x, y, dir + 1);
			Solve(x, y, dir + 2);
			Solve(x, y, dir + 3);
		}
		DFS(index + 1);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				map[i][j] = tmp[i][j];
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) cctv.push_back({ i, j });
		}

	DFS(0);
	cout << ans;
}