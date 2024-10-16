#include <iostream>
#include <algorithm>
using namespace std;

int k, total = 0;
string gear[4];

void Rotate(int num, int dir) { // dir : 1 => 시계방향
	int dirs[4] = {};
	dirs[num] = dir;

	int idx = num;
	while (idx > 0 && gear[idx][6] != gear[idx - 1][2]) {
		dirs[idx - 1] = -dirs[idx];
		idx--;
	}

	idx = num;
	while (idx < 3 && gear[idx][2] != gear[idx + 1][6]) {
		dirs[idx + 1] = -dirs[idx];
		idx++;
	}

	for (int i = 0; i < 4; i++)
	{
		if (dirs[i] == -1)
			rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
		else if(dirs[i] == 1)
			rotate(gear[i].begin(), gear[i].end() - 1, gear[i].end());
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int s = 0; s < 4; s++)
			cin >> gear[s];  // N은 0 // S는 1

	cin >> k;
	while (k--) 
	{
		int num, dir;
		cin >> num >> dir; // 몇번째 톱니바퀴 + 방향 // 1 시계방향 // 2 반시계방향

		Rotate(num - 1, dir);
	}

	for (int i = 0; i < 4; i++)
		if (gear[i][0] == '1') total += (1 << i);

	cout << total;
}