#include <iostream>
#include <list>
using namespace std;

int n;

int main() {
	cin >> n;

	while (n--)
	{
		string input; cin >> input;
		list<char> m_list = {};
		auto cur = m_list.begin();

		for (auto i : input)
		{
			if (i == '<' )
			{
				if(cur != m_list.begin())
					cur--;
			}
			else if (i == '>')
			{
				if(cur != m_list.end())
					cur++;
			}
			else if (i == '-' )
			{
				if (cur != m_list.begin())
				{
					cur--;
					cur = m_list.erase(cur);
				}
			}
			else
				m_list.insert(cur, i);
		}

		for (auto i : m_list)
			cout << i;
		cout << "\n";
	}
}