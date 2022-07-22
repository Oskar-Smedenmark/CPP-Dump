#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int guess = 0;
	int tries = 0;
	int randomNr = 0;
	int highestNr = 0;
	int lowestNr = 0;
	int divider = 1;
	int nrOfTries = 0;
	

	cout << "Skriv in det st\x94rsta talet: ";
	cin >> highestNr;
	cout << "Skriv in det l\x84gsta talet: ";
	cin >> lowestNr;
	cout << "Gissa ett tal mellan " << lowestNr << " och " << highestNr << endl;

	randomNr = rand() % highestNr + lowestNr + 1;
	divider = highestNr;
	while (divider > 0)
	{
		divider /= 2;
		nrOfTries++;	
	}

	while (guess != randomNr && tries != nrOfTries)
	{
		cout << "Din gissning: ";
		cin >> guess;
		if (guess == randomNr)
		{
			cout << "Du gissade r\x84tt!" << endl;
			cout << "Det tog dig " << tries << " f\x94rs\x94k!" << endl;
		}
		else
		{
			cout << "Fel!" << endl;
		}
		if (guess < randomNr)
		{
			cout << "Det var f\x94r l\x86gt!" << endl;
		}
		else if (guess > randomNr)
		{
			cout << "Det var f\x94r h\x94gt!" << endl;
		}
		tries++;
	}
	if (tries >= nrOfTries && guess != randomNr)
	{
		cout << "Du misslyckades p\x86 alla dina " << nrOfTries << " f\x94rs\x94k! bad luck!" << endl;
	}
	return 0;
}