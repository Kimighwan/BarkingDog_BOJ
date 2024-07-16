#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int t, n;
int arr[100'001];
int state[100'001];

constexpr int NOT_VISITED = 0;
//constexpr int VISITED = 1; // 방문 표시를 x 시작 숫자로 표현 // state[cur] = x;
constexpr int CYCLE = -1; 
// constexpr int NOT_CYCLE = 3; // 그냥 양수로 표현

void func(int x) {
	int cur = x;
	while (1)
	{
		state[cur] = x;
		cur = arr[cur];

		if (state[cur] == x) // 이미 방문함
		{
			while (state[cur] != CYCLE)
			{
				state[cur] = CYCLE;
				cur = arr[cur];
			}
			return;
		}
		else if (state[cur] != 0) return;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		fill(state + 1, state + n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> arr[i];

		int cnt = 0;

		for (int i = 1; i <= n; i++) 
			if (state[i] == NOT_VISITED) func(i);

		for (int i = 1; i <= n; i++)
			if (state[i] != CYCLE) cnt++;

		cout << cnt << '\n';
	}
}