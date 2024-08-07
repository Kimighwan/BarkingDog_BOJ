#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, p;
int map[1001][1001];
int step[10];
int area[10];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
queue<tuple<int, int, int>> q[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++)
		cin >> step[i];

	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '.') map[i][j] = 1;
			else if (c == '#') map[i][j] = 0;
			else {
				map[i][j] = 0;
				q[c - '0'].push({ i, j, 0 });
				area[c - '0'] += 1;
			}
		}
	}

	while (1) {
		bool end = 0;

		for (int i = 1; i <= p; i++) {
			queue<tuple<int, int, int>> nextq;
			while (!q[i].empty()) {
				int curx, cury, curStep;
				tie(curx, cury, curStep) = q[i].front();
				q[i].pop();
				if (curStep >= step[i]) {
					nextq.push({ curx, cury, 0 });
					continue;
				}

				for (int dir = 0; dir < 4; dir++) {
					int nx = curx + dx[dir], ny = cury + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (!map[nx][ny]) continue;
					q[i].push({ nx, ny, curStep + 1 });
					map[nx][ny] = 0;
					area[i]++;
					end = 1;
				}
			}
			q[i] = nextq;
		}
		if (!end) break;
	}

	for (int i = 1; i <= p; i++)
		cout << area[i] << ' ';
}