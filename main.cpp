#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int Size = 52;
int Pocket[Size];

void RandomPick()
{
	for (int i = 0; i < Size; ++i)
	{
		Pocket[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = Size - 1; i > 0; --i)
	{
		int j = rand() % (i + 1);
		swap(Pocket[i], Pocket[j]);
	}

	cout << "Shuffled Pocket: ";
	for (int i = 0; i < Size; ++i)
	{
		cout << Pocket[i] << " ";
	}
}

int main()
{
	RandomPick();

	cout << endl;

	return 0;
}