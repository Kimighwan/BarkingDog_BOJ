#include <iostream>
using namespace std;

string a, b;
int alp[26];
int cnt = 0;

int main() {
	cin >> a >> b;

	for (int i = 0; i < (int)a.size(); i++)
	{
		alp[a[i] - 'a']++;
	}
	for (int i = 0; i < (int)b.size(); i++)
	{
		alp[b[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{
		if(alp[i] > 0) cnt += alp[i];
		else cnt -= alp[i];
	}

	cout << cnt;
}