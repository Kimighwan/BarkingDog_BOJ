#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string map[26];
bool visit[26][26];
vector<int> result;

int dx[4] = { 0 , 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] || map[i][j] == '0') continue;

			q.push({ i, j });
			visit[i][j] = true;
			int cnt = 1;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visit[nx][ny] || map[nx][ny] == '0') continue;
					q.push({ nx, ny });
					visit[nx][ny] = true;
					cnt++;
				}
			}
			result.push_back(cnt);
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
}