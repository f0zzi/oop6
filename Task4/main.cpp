#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;

int main()
{
	srand(time(nullptr));
	vector<string> words = { "pineapple", "penguin", "table" };
	vector<string> description = { "Tropical plant with an edible fruit, also called ananas.",
									"Aquatic flightless birds. They live almost exclusively in the Southern Hemisphere.",
									"Item of furniture with a flat top and one or more legs." };
	int wordNumber = rand() % words.size();
	int attempts = 5 + words[wordNumber].size();
	string answer = words[wordNumber];
	string dotedAnswer;
	for (char element : answer)
		dotedAnswer.append("*");
	string question = description[wordNumber];
	string usedLetters;
	string letter;
	bool guessed;
	while (attempts > 0 && (guessed = (dotedAnswer.find("*") != string::npos)))
	{
		system("cls");
		cout << "----------------- Guess the word game ------------------------\n";
		cout << "Word description: " << question << endl;
		cout << "Word: " << dotedAnswer << endl;
		cout << "Attempt left: " << attempts << endl;
		cout << "Guess a letter: ";
		cin >> letter;
		if (!isalpha(letter[0]) || letter.size() != 1)
		{
			cout << "Wrong input. Try again." << endl;
			system("pause");
			continue;
		}
		letter[0] = tolower(letter[0]);
		if (usedLetters.find(letter) == string::npos)
		{
			usedLetters.append(letter);
			attempts--;
			int pos = 0;
			while ((pos = answer.find(letter, pos)) != string::npos)
				dotedAnswer.replace(pos++, 1, letter);
		}
		else
		{
			cout << "You already used this letter. Be more attentive." << endl;
			system("pause");
		}
	}
	system("cls");
	if (!guessed)
		cout << "Congratulations you WIN!!!" << endl;
	else
		cout << "Sorry. You lose." << endl;
	cout << "Answer was: " << answer << endl;
	system("pause");
	return 0;
}