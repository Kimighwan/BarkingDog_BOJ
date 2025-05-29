#include <iostream>
using namespace std;

int alp[26];
string s;

int main() {
	cin >> s;

	//memset(alp, 0, sizeof alp);

	for (int i = 0; i < (int)s.size(); i++)
	{
		alp[s[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
		cout << alp[i] << " ";
}