#include <iostream>
#include <string>
#include <vector>
using namespace std;

void NameDigits(string& str);

int main()
{
	string example = "15 apples 2 plums";
	NameDigits(example);
	cout << example << endl;
	system("pause");
	return 0;
}

void NameDigits(string& str)
{
	int pos = 0;
	vector<string> namesDigits { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	while ((pos = str.find_first_of("1234567890", pos)) != string::npos)
		str.insert(pos, "(" + namesDigits[stoi(str.substr(pos++, 1))] + ")");
}