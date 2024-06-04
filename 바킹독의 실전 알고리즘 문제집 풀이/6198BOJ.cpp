#include <iostream>
#include <stack>

using namespace std;
stack<long long> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long result = 0;
	cin >> n;

	while (n--) {
		long long h;
		cin >> h;
		while (!s.empty() && s.top() <= h)
			s.pop();
		result += s.size();
		s.push(h);
	}


	cout << result;
}