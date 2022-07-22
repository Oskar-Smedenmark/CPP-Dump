#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*const int CAPACITY = 5;
	int nrs[CAPACITY] = { 4, 9, 12, 7, 3 };
	int nrsCopy[CAPACITY] = { };
	int counter = 0;
	bool same = true;
	
	for (int i = 0; i < CAPACITY; i++)
	{
		nrsCopy[i] = nrs[i];
		cout << nrsCopy[i] << " ";
	}
	nrsCopy[1] = 7;
	for (int i = 0; i < CAPACITY; i++)
	{
		if (nrsCopy[i] != nrs[i])
		{
			same = false;
		}
	}
	cout << endl;
	while (same && counter != 4)
	{
		if (nrsCopy[counter] != nrs[counter])
		{
			same = false;
		}
		cout << nrsCopy[counter] << " ";
		counter++;
	}
	if (same == true)
	{
		cout << endl << "De var lika!" << endl;
	}
	else
	{
		cout << endl << "De var inte lika!" << endl;
	}*/

	//Att ta bort i en array
	//1) Flytta alla "värden" efter det bortagna ett steg åt vänster
	//2) ersätt den som tas bort med den som är "sist"
	const int CAPACITY = 7;
	string names[CAPACITY] = { "Bo", "Ola", "Lisa", "Stina" };
	string toFind = "";
	int nrOfNames = 4;
	int index = 0;
	bool found = false;

	cout << "Mata in ett namn: ";
	cin >> names[nrOfNames];
	nrOfNames++;

	cout << "Hitta ett namn: ";
	cin >> toFind;

	while (found == false && index < nrOfNames)
	{
		if (toFind == names[index])
		{
			found = true;
		}
		else
		{
			index++;
		}
	}
	if (found == true)
	{
		cout << "Namnet hittades på position " << index << " i arrayen" << endl;
		//Ersätt med sista
		/*names[index] = names[nrOfNames - 1];
		nrOfNames--;*/
		//Alternativt flytta efterföljare
		for (int i = index; i < nrOfNames - 1; i++)
		{
			names[i] = names[i + 1];
			cout << names[i] << " ";
		}
		nrOfNames--;
	}
	else
	{
		cout << "Namnet hittades inte!" << endl;
	}




	return 0;
}