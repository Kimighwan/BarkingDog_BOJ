#include <iostream>
#include <queue>
#include <tuple> 
using namespace std;

char map[6][6];
int cnt = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool chk[25];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];

	fill(chk + 7, chk + 25, true);

	do 
	{
		queue<pair<int, int>> q;
		int s = 0, cur = 0; // s : 다솜파 // cur : 몇개 선택?
		bool is7[5][5] = {}, visit[5][5] = {}; // is7 : 칠공주 선택? 

		for (int i = 0; i < 25; i++)
			if (!chk[i])
			{
				int x = i / 5; // 행
				int y = i % 5; // 얄
				is7[x][y] = true;
				if (q.empty())
				{
					q.push({ x, y });
					visit[x][y] = true;
				}
			}
		
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			cur++;
			if (map[x][y] == 'S') s++;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || !is7[nx][ny] || visit[nx][ny]) continue;
				q.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}

		cnt += (cur >= 7 && s >= 4);

	} while (next_permutation(chk, chk + 25));
	cout << cnt;
}
