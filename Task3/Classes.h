#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Time
{
private:
	friend class Train;
	int hour;
	int min;
public:
	Time() :Time(0, 0) {}
	Time(int hour, int min)
	{
		SetTime(0, 0);
	}
	void ShowTime() const
	{
		if (hour < 10)
			cout << "0";
		cout << hour << ":";
		if (min < 10)
			cout << "0";
		cout << min << endl;
	}
	pair<int, int> GetTime() const
	{
		return { hour, min };
	}
	bool SetTime(int hour, int min)
	{
		if (hour <= 23 && hour >= 0)
			if (min <= 59 && min >= 0)
			{
				this->hour = hour;
				this->min = min;
				return true;
			}
		return false;
	}
	void SetTime()
	{
		int hour, min;
		do
		{
			cout << "Enter hours: ";
			cin >> hour;
			cout << "Enter minutes: ";
			cin >> min;
			if (SetTime(hour, min))
				break;
			else
				cout << "Invalis input. Try again.\n";
		} while (true);
	}
};

class Train
{
private:
	size_t number;
	string destinationPlace;
	Time arriveTime;
	static int counter;
public:
	Train() :Train("Nowhere", 0, 0) {}
	Train(string destinationPlace, int hour, int min)
	{
		this->number = counter++;
		this->destinationPlace = destinationPlace;
		arriveTime.SetTime(hour, min);
	}
	void ShowInfo() const
	{
		cout << "#" << number << "\t Destination: " << destinationPlace << "\t Arrive time: ";
		arriveTime.ShowTime();
	}
	void SetDestination()
	{
		string destination;
		cout << "Enter destination: ";
		cin >> destination;
		this->destinationPlace = destination;
	}
	void SetTrain()
	{
		SetDestination();
		arriveTime.SetTime();
	}
	bool operator <(const Train& other)
	{
		if (arriveTime.hour == other.arriveTime.hour)
			return arriveTime.min < other.arriveTime.min;
		else
			return arriveTime.hour < other.arriveTime.hour;
	}
	int GetNumber() const
	{
		return number;
	}
};
int Train::counter = 1;
class RailWay
{
private:
	vector<Train> trains;
public:
	RailWay()
	{
		trains = { {"London", 23, 55},
	{"Paris", 0, 55},
	{"Berlin", 1, 00} };
	}
	void AddTrain()
	{
		Train tmp;
		tmp.SetTrain();
		trains.push_back(tmp);
	}
	void RemoveTrain()
	{
		if (trains.size() > 1)
		{
			int number;
			bool found = false;
			do
			{
				cout << "Enter train number to remove: ";
				cin >> number;
				for (size_t i = 0; i < trains.size(); i++)
				{
					if (trains[i].GetNumber() == number)
					{
						trains.erase(trains.begin() + i);
						found = true;
						break;
					}
				}
				cout << "Invalid number. Try again.\n";
			} while (!found);
		}
		else if (trains.size() == 1)
			trains.erase(trains.begin());
		else
		{
			cout << "There no trains to remove.\n";
			system("pause");
		}
	}
	void EditTrain()
	{
		if (trains.size() > 1)
		{
			int number;
			bool found = false;
			do
			{
				cout << "Enter train number to edit: ";
				cin >> number;
				for (size_t i = 0; i < trains.size(); i++)
				{
					if (trains[i].GetNumber() == number)
					{
						trains[i].SetTrain();
						found = true;
						break;
					}
				}
				cout << "Invalid number. Try again.\n";
			} while (!found);
		}
		else if (trains.size() == 1)
			trains[0].SetTrain();
		else
		{
			cout << "There no trains to edit.\n";
			system("pause");
		}
	}
	void ShowShedule()
	{
		if (trains.size() > 0)
		{
			sort(trains.begin(), trains.end());
			for (Train elem : trains)
				elem.ShowInfo();
		}
		else
			cout << "------------------  SORRY NO TRAINS FOR TODAY  ---------------------\n";
		cout << endl;
	}
};