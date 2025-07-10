#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> Q;
int result = 0, cnt = 0;
int arr[51];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		Q.push_back(i);

	while (cnt != m)
	{
		if (Q.front() == arr[cnt])
		{
			Q.pop_front();
			cnt++;
		}
		else if (n / 2 >= Q[arr[cnt]])
		{
			Q.push_back(Q.front());
			Q.pop_front();
			result++;
		}
		else
		{
			Q.push_front(Q.back());
			Q.pop_back();
			result++;
		}
	}

	cout << result;
}