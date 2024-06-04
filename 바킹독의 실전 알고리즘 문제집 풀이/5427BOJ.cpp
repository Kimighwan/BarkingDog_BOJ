#include <iostream>
#include <queue>
using namespace std;

int t, w, h;
int map[1001][1001];
int me[1001][1001];
int fire[1001][1001];
int dx[4] = { 0 , 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		bool escape = false;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			fill(me[i], me[i] + w, -1);
			fill(fire[i], fire[i] + w, -1);
		}


		queue<pair<int, int>> q_me;
		queue<pair<int, int>> q_fire;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
			{
				char c;
				cin >> c;

				if (c == '#')
					map[i][j] = -1;
				else {
					if (c == '@') {
						me[i][j] = 0;
						q_me.push({ i, j });
					}
					if (c == '*') {
						fire[i][j] = 0;
						q_fire.push({ i, j });
					}
					map[i][j] = 0;
				}
			}
		}

		while (!q_fire.empty())
		{
			int x = q_fire.front().first;
			int y = q_fire.front().second;
			q_fire.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (fire[nx][ny] >= 0 || map[nx][ny] == -1) continue;
				fire[nx][ny] = fire[x][y] + 1;
				q_fire.push({ nx, ny });
			}
		}

		while (!q_me.empty() && !escape)
		{
			int x = q_me.front().first;
			int y = q_me.front().second;
			q_me.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				{
					cout << me[x][y] + 1 << '\n';
					escape = true;
					break;
				}
				if (fire[nx][ny] != -1 && fire[nx][ny] <= me[x][y] + 1) continue;
				if (me[nx][ny] >= 0) continue;
				if (map[nx][ny] == -1) continue;
				me[nx][ny] = me[x][y] + 1;
				q_me.push({ nx, ny });
			}
		}
		if(!escape) cout << "IMPOSSIBLE" << '\n';
	}
}