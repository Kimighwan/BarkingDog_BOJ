#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[51][51]; // 0 : 빈칸 // 1 : 집 // 2 : 치킨집
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; // n : 맵 크기 // m : 최대 치킨 갯수
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) chicken.push_back({ i, j });
			if (map[i][j] == 1) house.push_back({ i, j });
		}

	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
	int total = 0x7f7f7f7f;

	do 
	{
		int dist = 0;
		for (auto h : house)
		{
			int tmp = 0x7f7f7f7f;
			for (int i = 0; i < chicken.size(); i++)
			{
				if (brute[i] == 0) continue;
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			dist += tmp;
		}
		total = min(total, dist);
	} while (next_permutation(brute.begin(), brute.end()));

	cout << total;
} // 도시의 치킨 거리 최솟값 출력