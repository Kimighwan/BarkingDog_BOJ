#include <iostream>
#include <list>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	list<int> L;
	
	for (int i = 1; i <= n; i++)
		L.push_back(i);

	auto cur = L.begin();

	cout << *cur;
}