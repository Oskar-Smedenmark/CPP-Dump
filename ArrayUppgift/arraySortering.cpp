#include <iostream>

using namespace std;

int main()
{
	int* values = nullptr;
	values = new int[4];
	values[0] = 10;
	values[2] = 20;
	values[3] = 30;
	values[4] = 40;
	int* temp = new int[4 * 2];
	
	for (int i = 0; i < 4; i++)
	{
		temp[i] = values[i];
	}
	delete[]temp;
	delete[]values; //Återlämnar minnet


	return 0;
}