#include <iostream>
#include <Windows.h>
#include "Classes.h"
using namespace std;

int main()
{
	RailWay rail;
	int selection;
	do
	{
		system("cls");
		cout << "Train shedule:\n";
		rail.ShowShedule();
		cout << "Shedule menu:\n";
		cout << "1 - Add train\n";
		cout << "2 - Remove train\n";
		cout << "3 - Edit train\n";
		cout << "0 - Exit\n";
		cout << "Selection: ";
		cin >> selection;
		system("cls");
		cout << "Train shedule:\n";
		rail.ShowShedule();
		switch (selection)
		{
		case 1:
			cout << "Adding train:\n";
			rail.AddTrain();
			break;
		case 2:
			cout << "Removing train:\n";
			rail.RemoveTrain();
			break;
		case 3:
			cout << "Edit train:\n";
			rail.EditTrain();
			break;
		case 0:
			cout << "Have a nice day.\n";
			system("pause");
			break;
		default:
			cout << "Invalid input. Try again.\n";
			system("pause");
			break;
		}
	} while (selection != 0);
	return 0;
}