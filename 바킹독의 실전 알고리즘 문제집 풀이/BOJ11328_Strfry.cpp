#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main() {
	cin >> n;

	while (n--)
	{
		string a, b;
		int alp[26] = {};
		int len = 0;
		bool check = false;
		cin >> a >> b;

		//fill(alp, alp + 26, 0);

		for (int i = 0; i < (int)a.size(); i++)
		{
			alp[a[i] - 97]++;
			len++;
		}

		for (int i = 0; i < (int)b.size(); i++)
		{
			alp[b[i] - 97]--;
			len--;
		}

		if (len != 0) {
			cout << "Impossible" << "\n";
			continue;
		}
		
		for (int i = 0; i < 26; i++)
		{
			if (alp[i] != 0)
				check = true;
		}

		if (check) cout << "Impossible" << "\n";
		else
			cout << "Possible" << "\n";
	}
}