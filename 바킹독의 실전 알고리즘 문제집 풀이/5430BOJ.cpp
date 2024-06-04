#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void Parse(string& input, deque<int>& d) {
	int cur = 0;
	for (int i = 1; i + 1 < input.size(); i++)
	{
		if (input[i] == ',')
		{
			d.push_back(cur);
			cur = 0;
		}
		else cur = 10 * cur + (input[i] - '0');
	}
	if (cur != 0) d.push_back(cur);
}

void Print(deque<int> & d) {
	cout << "[";
	for (int i = 0; i < d.size(); i++) {
		cout << d[i];
		if (i + 1 != d.size()) cout << ", ";
	}
	cout << "]\n";
}

int main() {
	ios::ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		deque<int> d;
		string p, input;
		cin >> p;

		int n;
		cin >> n;
		cin >> input;
		Parse(input, d);
		int rev = 0;
		bool err = false;

		for (char c : p)
		{
			if (c == 'R')
			{
				rev = 1 - rev;
			}
			else
			{
				if (d.empty())
				{
					err = true;
					break;
				}

				if (!rev) d.pop_front();
				else d.pop_back();
			}
		}

		if (err) cout << "error\n";
		else
		{
			if (rev) reverse(d.begin(), d.end());
			Print(d);
		}
	}
}