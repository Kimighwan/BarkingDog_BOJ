#include <iostream>
#include <utility>
using namespace std;

int n, m, k;
int note[42][42];
int r, c;
int sti[12][12];

void Rotate() { // 90도 회전 
	int tmp[12][12];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[i][j] = sti[i][j];

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			sti[i][j] = tmp[r - j - 1][i];

	swap(r, c);
}

bool Pastable(int x, int y) { // 노트북에 붙일 수 있는가? // 가능하면 note 초기화 후 true 반환
	for(int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (note[x + i][y + j] == 1 && sti[i][j] == 1)
				return false;                         // 붙일 수 있는가? // 없어용 : false


	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) // 노트에 붙여주기
			if (sti[i][j] == 1)
				note[x + i][y + j] = 1;

	return true; // 붙일 수 있어용
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	while (k--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> sti[i][j]; // 스티커 입력


		for (int rot = 0; rot < 4; rot++) // 4방향이니 4번 시도해 근데 중간에 스티커 붙이면 빠져나와 -> flag 필요해 보여
		{
			bool isPast = false; // 스티커 붙였는가?
			for (int i = 0; i <= n - r; i++)
			{
				if (isPast) break;
				for (int j = 0; j <= m - c; j++)
				{
					if (Pastable(i, j))
					{
						isPast = true;
						break;
					}
				}
			}
			
			if (isPast) break;
			Rotate();
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += note[i][j];

	cout << cnt;
}