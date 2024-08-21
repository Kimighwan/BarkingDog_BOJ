// 간단하게 맵 복사해서 물과 인접한 빙판 녹이고, 백조 움직여 만나는지 판단후 
// 못 만나면 visit 초기화후 다시 진행 ==> 시간초과
//
// 많은 queue를 사용 백조에 대한 현재 Queue, 백조에 대한 Next Queue, 물에 대한 현재 Queue, 물에 대한 Next Queue
// While 돌리면서 백조와 물에 대한 BFS 1번씩 돌림
// 
// 백조 BFS : 인접한 방향이 물이라면 : 현재 Queue에 Push후 계속 진행.     
// 인접한 방향이 빙판이라면 : 백조의 Next Queue에 Push후 진행.     
// 인접한 방향이 백조라면 : 서로 만났다는 것을 Check 해준 후 종료.
//
// 물에 대한 BFS는 물에 해당하는 지점 queue에 다 넣고 인접한 방향이 빙판이면 next queue에 넣고 진행 그리고 물로 바꾸기


#include <iostream>
#include <queue>

#define MAX 1501

using namespace std;

char map[MAX][MAX];
int visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int r, c, si, sj;
bool Find = false;

queue<pair<int, int>> swan_q, swan_nq, q, nq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 'X') q.push({ i, j });
			if (map[i][j] == 'L')
			{
				si = i;
				sj = j;
			}
		}
	}

	int day = 0;

	swan_q.push({ si, sj });
	visit[si][sj] = true;

	while (!Find)
	{
		while (!swan_q.empty() && !Find) // 백조 찾기
		{
			int x = swan_q.front().first;
			int y = swan_q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (visit[nx][ny]) continue;
				
				visit[nx][ny] = true;

				if (map[nx][ny] == '.') swan_q.push({ nx, ny });
				else if (map[nx][ny] == 'X') swan_nq.push({ nx, ny });
				else if (map[nx][ny] == 'L')
				{
					Find = true;
					break;
				}
			}
		}

		while (!Find)
		{
			while(!q.empty()) // 물 녹이기
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (map[nx][ny] == 'X')
					{
						nq.push({ nx, ny });
						map[nx][ny] = '.';
					}
				}
			}
			day++;

			q = nq;
			swan_q = swan_nq;
			while (!nq.empty()) nq.pop();
			while (!swan_nq.empty()) swan_nq.pop();
		}
	}
	cout << day;
}