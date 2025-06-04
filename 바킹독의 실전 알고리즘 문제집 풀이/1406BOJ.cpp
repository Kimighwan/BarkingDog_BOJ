#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*string init;
	cin >> init;

	list<char> l;
	for (auto c : init) l.push_back(c);
	auto cur = l.end();

	int m;
	cin >> m;

	while (m--) {
		char op;
		cin >> op;
		if (op == 'L' && cur != l.begin())
			cur--;
		else if (op == 'D' && cur != l.end())
			cur++; 
		else if (op == 'B' && cur != l.begin()) {
			cur--;
			cur = l.erase(cur);
		}
			
		else if (op == 'P') {
			char add;
			cin >> add;
			l.insert(cur, add);
		}
	}

	for (auto c : l) cout << c;*/

	string arr;
	cin >> arr;

	list<char> m_list;
	for (auto i : arr) m_list.push_back(i);
	list<char>::iterator cur = m_list.end();

	int m; cin >> m;

	while (m--)
	{
		char op; cin >> op;

		if (op == 'L' && cur != m_list.begin())
			cur--;
		else if (op == 'D' && cur != m_list.end())
			cur++;
		else if (op == 'B' && cur != m_list.begin())
		{
			cur--;
			cur = m_list.erase(cur);
		}
		else if (op == 'P')
		{
			char x; cin >> x;
			m_list.insert(cur, x);
		}
	}

	for (auto c : m_list) cout << c;
}