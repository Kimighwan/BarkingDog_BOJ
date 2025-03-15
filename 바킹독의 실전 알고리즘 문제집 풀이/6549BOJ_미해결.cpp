#include <iostream>
#include <stack>

// 높이가 작아지면 최소 높이 체크하고 최소 높이 기준이로 너비 비교
// 높이가 커지면 해당 사각형 너비와 마지막 너비 구한 높이 기준으로 새로운 사각형을 포함한 너비로 비교

using namespace std;
int main() {
	ios::ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		stack < pair <long long, long long>> s;	// 높이, 처음 등장하는 index
		long long result = 0;
		for (int i = 0; i < n; i++)
		{
			int h;
			cin >> h;
			int index = i;
			while (!s.empty() && s.top().first >= h)
			{
				result = max(result, (i - s.top().second) * s.top().first);
				index = s.top().second;
				s.pop();
			}
			s.push({ h, i });
	}
}