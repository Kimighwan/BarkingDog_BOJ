#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char map[12][6];
bool visit[12][6];
int tmpCnt = 0; // 같은색 갯수
int result = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> boomV;

void DFS(int x, int y) { 

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
		if (map[nx][ny] == '.') continue;
		if (visit[nx][ny] || map[x][y] != map[nx][ny]) continue;

		tmpCnt++;
		visit[nx][ny] = true;
		boomV.push_back({ nx, ny });
		DFS(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];
	}

	while (1) 
	{
		bool flag = false;
		memset(visit, 0, sizeof(visit));
		boomV.clear();
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] == '.' || visit[i][j]) continue;

				tmpCnt = 1; // 탐색 시작 하는 색 1개 부터 시작
				boomV.push_back({ i, j });
				visit[i][j] = true;
				DFS(i, j);

				if (tmpCnt >= 4) // 4개 이상 겹침 -> 터트려야 함
				{
					flag = true; // 터졌음

					for (int i = 0; i < boomV.size(); i++)
					{
						map[boomV[i].first][boomV[i].second] = '.'; // 터트리기
					}
				}
				boomV.clear();
			}
		}

		// 한 번 맵 보고 터트리고 맵 정리 시작
		for (int i = 10; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] == '.') continue;
				int tmp = i;

				while (1)
				{
					if (tmp == 11 || map[tmp + 1][j] != '.') break;
					map[tmp + 1][j] = map[tmp][j];
					map[tmp][j] = '.';
					tmp++;
				}
			}
		}

		if (flag) result++; // 한 번 맵 전체를 돌고 나와서 터졌으면 연쇄 터짐 횟수 증가
		else break;
	}
	cout << result;
}