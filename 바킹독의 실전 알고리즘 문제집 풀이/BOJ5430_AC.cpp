#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int T, n;
string op;
deque<int> D;
string x;

void Parse() {
	int cur = 0;
	for (int i = 1; i + 1 < x.size(); i++)
	{

		if (x[i] == ',') {
			D.push_back(cur);
			cur = 0;
		}
		else cur = cur * 10 + (x[i] - '0');
	}
	if (cur != 0) D.push_back(cur);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> op >> n;
		bool check = false;
		int front = 1;
		D.clear();

		cin >> x;

		Parse();


		for (int i = 0; i < op.size(); i++)
		{
			if (op[i] == 'D')
			{
				if (D.empty())
				{
					cout << "error" << "\n";
					check = true;
					break;
				}
				else
				{
					if (front == 1)
					{
						D.pop_front();
					}
					else
					{
						D.pop_back();
					}
				}
			}
			else
			{
				front *= -1;
			}
		}

		if (!check)
		{
			if (front == -1) reverse(D.begin(), D.end());

			cout << "[";

			for (auto i = D.begin(); i != D.end(); i++)
			{
				cout << *i;
				if (i != D.end() - 1) cout << ",";
			}

			cout << "]" << "\n";
		}
	}
}