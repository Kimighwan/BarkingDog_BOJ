#include <iostream>
#include <queue>
using namespace std;

int r, c;
string map[1002];
int jihun[1002][1002];
int fire[1002][1002];
int dx[4] = { 0 , 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q_fire;
	queue<pair<int, int>> q_jihun;

	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		fill(jihun[i], jihun[i] + c, -1);
		fill(fire[i], fire[i] + c, -1);
	}

	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'F') {
				q_fire.push({ i, j });
				fire[i][j] = 0;
			}
			if (map[i][j] == 'J') {
				q_jihun.push({ i, j });
				jihun[i][j] = 0;
			}
		}
	}

	while (!q_fire.empty()) {
		int x = q_fire.front().first;
		int y = q_fire.front().second;
		q_fire.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (fire[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			fire[nx][ny] = fire[x][y] + 1;
			q_fire.push({ nx, ny });
		}
	}

	while (!q_jihun.empty()) {
		int x = q_jihun.front().first;
		int y = q_jihun.front().second;
		q_jihun.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				cout << jihun[x][y] + 1;
				return 0;
			}
			if (jihun[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			if (/**/fire[nx][ny] != -1 && jihun[x][y] + 1 >= fire[nx][ny]) continue;
			jihun[nx][ny] = jihun[x][y] + 1;
			q_jihun.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
}