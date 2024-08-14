#include <iostream>
#include <queue>
using namespace std;

char map[1501][1501];
int visit[1501][1501];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int r, c;

queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'L') q.push({ i, j });
		}
	}
}