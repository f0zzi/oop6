#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Time
{
private:
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
	void ShowShedule()
	{
		for (Train elem : trains)
			elem.ShowInfo();
	}
};
