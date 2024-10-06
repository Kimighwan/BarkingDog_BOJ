#include <iostream>

using namespace std;

int n;
int map[22][22];
int tmp[22][22];

void Rotate() {
	int rotmp[22][22];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			rotmp[i][j] = tmp[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = rotmp[n - 1 - j][i];
}

void Push(int dir) { // dir : 0일 때 왼쪽 // 1일 때 아래쪽 // 2일 때 오른쪽 
	while (dir--) Rotate();
	for (int i = 0; i < n; i++)
	{
		int push[22] = {};
		int idx = 0;
		for (int j = 0; j < n; j++)
		{
			if (tmp[i][j] == 0) continue;
			if (push[idx] == 0)
				push[idx] = tmp[i][j];
			else if (push[idx] == tmp[i][j])
				push[idx++] *= 2;
			else
				push[++idx] = tmp[i][j];
		}
		for (int j = 0; j < n; j++) tmp[i][j] = push[j];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int mx = 0;
	for (int c = 0; c < 1024; c++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = map[i][j];

		int chk = c;

		for (int i = 0; i < 5; i++)
		{
			int dir = chk % 4;
			chk /= 4;
			Push(dir);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mx = max(mx, tmp[i][j]);
	}
	cout << mx;
}