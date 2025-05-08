#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long result = 0;
vector<int> seqP, seqN;

void F(vector<int> v)
{
	while (v.size() > 1)
	{
		result += *(v.end() - 1) * *(v.end() - 2);
		v.pop_back();
		v.pop_back();
	}
	if (v.size())
		result += v[0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int x;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 1) result++;
		else if (x <= 0)
			seqN.push_back(x);
		else
			seqP.push_back(x);
	}

	sort(seqP.begin(), seqP.end());
	sort(seqN.begin(), seqN.end(), greater<>());

	F(seqP);
	F(seqN);

	cout << result;
}