#include <iostream>
#include <queue>
using namespace std;

int n, m, year = 0;
int map[301][301];
int visit[301][301];
int tmp[301][301];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool Check(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m);
}

void Init() {
	for (int i = 0; i < n; i++) fill(visit[i], visit[i] + m, 0);
}

void Melting() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[i][j] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (Check(nx, ny) && map[nx, ny] == 0) tmp[i][j]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = max(0, map[i][j] - tmp[i][j]);
}

int State() { // 0 : ´Ù ³ìÀ½ // 1 : ÇÑ µ¢ÀÌ // 2 : ºÐ¸®µÊ
	int x = -1, y = -1;
	int cnt1 = 0; // ºù»ê °³¼ö
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (map[i][j]) {
				x = i;
				y = j;
				cnt1++;
			}
		}
	}

	if (cnt1 == 0) return 0;
	int cnt2 = 0; // ºÙ¾î ÀÖ´Â ºù»ê // cnt1 °°À¸¸é ÇÑµ¢ÀÌ // ¾Æ´Ï¸é µÎµ¢ÀÌ ÀÌ»ó
	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[x][y] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cnt2++;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (!Check(nx, ny) || map[nx][ny] <= 0 || visit[nx][ny] == 1) continue;
			q.push({ nx, ny });
			visit[nx][ny] = 1;
		}
	}
	if (cnt1 == cnt2) return 1;
	return 2;
}
		
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}

	while (1)
	{
		year++;
		Init();
		Melting();
		int check = State();
		if (check == 0) {
			cout << 0;
			return 0;
		}
		else if (check == 1) continue;
		else break;
	}
	cout << year;
}