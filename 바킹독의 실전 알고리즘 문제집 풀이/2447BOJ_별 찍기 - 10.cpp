#include <iostream>

using namespace std;

char map[2200][2200];

void Solve(int x, int y, int n) {
	if (n == 1){
		map[x][y] = '*';
		return;
	}

	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue;
			Solve(x + n / 3 * i, y + n / 3 * j, n / 3);
		}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		fill(map[i], map[i] + n, ' ');

	Solve(0, 0, n);
	for (int i = 0; i < n; i++)
		cout << map[i] << '\n';
}

//void print_star(int i, int j, int num) {
//	if ((i / num) % 3 == 1 && (j / num) % 3 == 1)
//		cout << ' ';
//	else {
//		if (num / 3 == 0)
//			cout << '*';
//		else
//			print_star(i, j, num / 3);
//	}
//}
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < num; j++) print_star(i, j, num);
//		cout << '\n';
//	}
//}