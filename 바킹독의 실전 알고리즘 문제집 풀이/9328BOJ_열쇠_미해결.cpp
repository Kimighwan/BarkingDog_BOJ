#include <iostream>
#include <queue>
using namespace std;

int t, h, w;
char map[120][120];
int visit[120][120];
string keystr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		queue<pair<int, int>> q;
		queue<pair<int, int>> door[26]; // ¸ø ¿¬ ¹®
		int key[26] = {};
		int cnt = 0;

		cin >> h >> w;

		for (int i = 0; i <= h + 1; i++) {
			fill(visit[i], visit[i] + w + 2, 0);
			fill(map[i], map[i] + w + 2, 0);
		}

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) cin >> map[i][j];

		cin >> keystr;
		for (auto c : keystr) key[c - 'a'] = 1;

		q.push({ 0, 0 });
		visit[0][0] = 1;

		while (!q.empty())
		{
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = curx + dx[dir];
				int ny = cury + dy[dir];
				if (nx < 0 || nx > h + 1 || ny < 0 || ny < w + 1) continue;
				if (visit[nx][ny] || map[nx][ny] == '*') continue;
				visit[nx][ny] = 1;

				if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z')
				{
					int k = map[nx][ny] - 'a';
					key[k] = 1;
					while (!door[k].empty())
					{
						auto ndoor = door[k].front();
						door[k].pop();
						q.push({ ndoor.first, ndoor.second });
					}
				}
				else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z')
				{
					int k = map[nx][ny] + 32 - 'a';
					if (!key[k])
					{
						door[k].push({ nx, ny });
						continue;
					}
				}
				else if (map[nx][ny] == '$') cnt++;
				q.push({ nx, ny });
			}
		}
		cout << cnt << "\n";
	}
}