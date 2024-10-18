#include <iostream>
#include <string>
using namespace std;

int good = 0, bad = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'H' || s[i] == 'P' || s[i] == 'Y') good++;
		else if (s[i] == 'S' || s[i] == 'D') bad++;
		else if (s[i] == 'A') { good++; bad++; }
	}

	if (good == bad) {
		cout << "50.00";
		return 0;
	}

	double ans = 100.0 * good / (good + bad);
	cout << fixed;
	cout.precision(2);
	cout << ans + 1e-6;