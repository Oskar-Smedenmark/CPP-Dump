#include <iostream>

using namespace std;

int main()
{
	int totalAmount = 0;
	int amountEnKronor = 0;
	int amountFemKronor = 0;
	int amountTioKronor = 0;
	int amountTjugolappar = 0;
	int amountFemtiolappar = 0;
	int amountHundralappar = 0;
	int amountFemhundralappar = 0;
	int amountTusenlappar = 0;
	int beginingMoney = 0;

	cout << "Skriv in hur mycket pengar du har: ";
	cin >> totalAmount;
	beginingMoney = totalAmount;
	amountTusenlappar = totalAmount / 1000;
	totalAmount = totalAmount % 1000;
	amountFemhundralappar = totalAmount / 500;
	totalAmount = totalAmount % 500;
	amountHundralappar = totalAmount / 100;
	totalAmount = totalAmount % 100;
	amountFemtiolappar = totalAmount / 50;
	totalAmount = totalAmount % 50;
	amountTjugolappar = totalAmount / 20;
	totalAmount = totalAmount % 20;
	amountTioKronor = totalAmount / 10;
	totalAmount = totalAmount % 10;
	amountFemKronor = totalAmount / 5;
	totalAmount = totalAmount % 5;
	amountEnKronor = totalAmount;

	cout << beginingMoney << " kr blir om man v\x84xlar: " << endl << amountTusenlappar << " tusenlappar, " << endl;
	cout << amountFemhundralappar << " femhundralappar, " << endl;
	cout << amountHundralappar << " hundralappar, " << endl;
	cout << amountFemtiolappar << " femtiolappar, " << endl;
	cout << amountTjugolappar << " tjugolappar, " << endl;
	cout << amountTioKronor << " tiokronor, " << endl;
	cout << amountFemKronor << " femkronor och " << endl;
	cout << amountEnKronor << " enkronor." << endl;




	return 0;
}