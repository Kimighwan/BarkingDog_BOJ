//    북
// 서    동
//    남
// ->  c 증가

#include <iostream>
using namespace std;

int n, m, x, y, k, command;
int map[22][22];
int dice[7];

int idx[5][4] = {
	{},        // dummy
	{2,6,4,5}, // 동쪽, 5->2, 2->6, 6->4, 4->5
	{2,5,4,6}, // 서쪽, 6->2, 2->5, 5->4, 4->6
	{3,2,1,4}, // 북쪽, 4->3, 3->2, 2->1, 1->4
	{2,3,4,1}, // 남쪽, 1->2, 2->3, 3->4, 4->1
};

bool isOk(int nx, int ny) {
	return (nx > 0 && nx <= n);
}

void F(int c) {
	int nx = x, ny = y;

	if (c == 1)
		++ny;
	else if (c == 2) --ny;
	else if (c == 3) --nx;
	else ++nx;
}

int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	while (k--)
	{
		cin >> command;
		F(command);
	}
}