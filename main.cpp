#include <iostream>
#include <algorithm>
#include <string>

#define CARD_COUNT		52

using namespace std;

//global variable
int Deck[CARD_COUNT] = { 0, };

void Initialize()
{
	srand((unsigned int)time(NULL));

	for (int Index = 0; Index < CARD_COUNT; Index++)
	{
		Deck[Index] = Index;
	}
}

void Shuffle()
{
	int Temp = 0;
	for (int Count = 0; Count < CARD_COUNT * 1000; Count++)
	{
		int First = rand() % CARD_COUNT;
		int Second = rand() % CARD_COUNT;
		Temp = Deck[First];
		Deck[First] = Deck[Second];
		Deck[Second] = Temp;
	}
}

int PrintCard(int CardRealNumber)
{
	//Type
// Heart, Clover, Space, Diamond
	int CardType = CardRealNumber / 13;
	int CardNumber = CardRealNumber % 13 + 1;
	int Score = CardNumber;

	string Types[4] = {
		"♥",
		"◆",
		"♣",
		"♠"
	};

	//if (CardType == 0)
	//{
	//	cout << "Heart";
	//}
	//else if (CardType == 1)
	//{
	//	cout << "Clover";
	//}
	//else if (CardType == 2)
	//{
	//	cout << "Space";
	//}
	//else // (CardType == 3)
	//{
	//	cout << "Diamond";
	//}

	cout << Types[CardType];

	if (CardNumber == 1)
	{
		cout << " A" << endl;
	}
	else if (CardNumber == 11)
	{
		cout << " J" << endl;
		Score = 10;
	}
	else if (CardNumber == 12)
	{
		cout << " Q" << endl;
		Score = 10;
	}
	else if (CardNumber == 13)
	{
		cout << " K" << endl;
		Score = 10;
	}
	else
	{
		cout << " " << CardNumber << endl;
	}

	return Score;
}

void Print()
{
	int ComputerScore = 0;
	int PlayerScore = 0;

	cout << "Computer" << endl;
	ComputerScore = ComputerScore + PrintCard(Deck[0]);
	ComputerScore += PrintCard(Deck[1]);
	cout << "Computer Score : " << ComputerScore << endl;

	cout << "================\n\n" << endl;

	cout << "Player" << endl;
	PlayerScore += PrintCard(Deck[2]);
	PlayerScore += PrintCard(Deck[3]);
	cout << "Player Score  : " << PlayerScore << endl;

	if (ComputerScore > 21)
	{
		cout << "you win" << endl;
	}
	else if (PlayerScore > 21)
	{
		cout << "you lose" << endl;

	}
	else if (PlayerScore >= ComputerScore)
	{
		cout << "you win" << endl;
	}
	else
	{
		cout << "you lose" << endl;
	}

}


int main()
{
	Initialize();
	Shuffle();
	Print();

	return 0;

	//[][][\0]
	//[][][\0]
	//[][][\0]
	//[][][\0]
	const char* Type[4] = {
		"♥",
		"◆",
		"♣",
		"♠"
	};

	//char Type[4][3] = {
	//	"♥",
	//	"◆",
	//	"♣",
	//	"♠"
	//};

	//문자열 X -> char Array
	//[A][B][\0][]
	char Temp[10] = "AB\0C";
	//Temp[0] = 'A';
	//Temp[1] = 'B';
	//Temp[2] = '\0';
	//cout << 111111;

	//string Types[4] = {
	//	"♥",
	//	"◆",
	//	"♣",
	//	"♠"
	//};

	//cout << Types[0] << endl;


	return 0;
}