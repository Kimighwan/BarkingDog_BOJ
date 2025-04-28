#include <iostream>
#include <string>
using namespace std;

string input, tmp;
int result = 0;
bool isMinus = false;

int main() {
	cin >> input;

	for (int i = 0; i <= input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-' || input.size() == i)
		{
			if (isMinus)
			{
				result -= stoi(tmp);
				tmp = "";
			}
			else
			{
				result += stoi(tmp);
				tmp = "";
			}
		}
		else
			tmp += input[i];

		if (input[i] == '-') isMinus = true;
	}

	cout << result;
}