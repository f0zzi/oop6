#include <iostream>
#include <string>
using namespace std;

bool ValidateIp(const string& str);

int main()
{
	string ip1 = "255.255.255.0";
	string ip2 = "255.255.0.256";
	string ip3 = "192.0.157";
	string ip4 = "192.0.157.1.1";
	string ip5 = "192.0.157.";
	cout << ip1 << "\t is valid: " << boolalpha << ValidateIp(ip1) << endl;
	cout << ip2 << "\t is valid: " << boolalpha << ValidateIp(ip2) << endl;
	cout << ip3 << "\t is valid: " << boolalpha << ValidateIp(ip3) << endl;
	cout << ip4 << "\t is valid: " << boolalpha << ValidateIp(ip4) << endl;
	cout << ip5 << "\t is valid: " << boolalpha << ValidateIp(ip5) << endl;
	system("pause");
	return 0;
}

bool ValidateIp(const string& str)
{
	int begin = 0, counter = 0;
	int end, value;
	do
	{
		end = str.find(".", begin);
		value = stoi(str.substr(begin, end - begin));
		if (value > 255 || value < 0 || (begin = end + 1) > str.size() - 1)
			break;
		counter++;
	} while (end != string::npos && counter <= 4);
	return counter == 4;
}
