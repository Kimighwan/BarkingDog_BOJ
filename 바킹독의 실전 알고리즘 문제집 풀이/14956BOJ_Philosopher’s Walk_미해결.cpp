// 입력 값 맵 크기 n 과 궁금한 좌표 index 번호 
#include <iostream>

using namespace std;

pair<int, int> Solve(int side, int walk) {
	if (side == 2) {
		switch (walk) {
		case 1: return { 1, 1 };
		case 2: return { 1, 2 };
		case 3: return { 2, 2 };
		case 4: return { 2, 1 };
		}
	}
	int half = side / 2, section = half * half;
	if (walk <= section)
	{
		pair<int, int> rv = Solve(half, walk);
		return { rv.first, rv.second };
	}
	else if (walk <= section * 2)
	{
		pair<int, int> rv = Solve(half, walk - section);
		return { rv.first, rv.second + half };
	}
	else if (walk <= section * 3)
	{
		pair<int, int> rv = Solve(half, walk - section * 2);
		return { rv.first + half, rv.second + half };
	}
	else
	{
		pair<int, int> rv = Solve(half, walk - section * 3);
		return { 2 * half - rv.second + 1, half - rv.first + 1 };
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	pair<int, int> ans = Solve(n, m);
	cout << ans.first << " " << ans.second;
}