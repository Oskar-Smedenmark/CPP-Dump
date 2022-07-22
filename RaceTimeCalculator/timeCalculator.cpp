#include <iostream>

using namespace std;

int main()
{
	int startHours = 0;
	int startMinutes = 0;
	int startSeconds = 0;
	int endHours = 0;
	int endMinutes = 0;
	int endSeconds = 0;
	int timeOutHours = 0;
	int timeOutMinutes = 0;
	int timeOutStartSeconds = 0;
	int timeOutEndSeconds = 0;
	int timeOutSeconds = 0;

	cout << "Skriv in hur mycket klockan var n\x84r racet startade h\x84r nedan i timmar, minuter och sekunder";
	cout << endl << "Timmar: ";
	cin >> startHours;
	cout << endl << "Minuter: ";
	cin >> startMinutes;
	cout << endl << "Sekunder: ";
	cin >> startSeconds;

	cout << endl << endl << "Skriv in hur mycket klockan var n\x84r du kom in i m\x86l h\x84r nedan i timmar, minuter och sekunder";
	cout << endl << "Timmar: ";
	cin >> endHours;
	cout << endl << "Minuter: ";
	cin >> endMinutes;
	cout << endl << "Sekunder: ";
	cin >> endSeconds;

	timeOutStartSeconds = startHours * 60 * 60;
	timeOutStartSeconds = timeOutStartSeconds + (startMinutes * 60);
	timeOutStartSeconds = timeOutStartSeconds + startSeconds;

	timeOutEndSeconds = endHours * 60 * 60;
	timeOutEndSeconds = timeOutEndSeconds + (endMinutes * 60);
	timeOutEndSeconds = timeOutEndSeconds + endSeconds;
	timeOutSeconds = timeOutEndSeconds - timeOutStartSeconds;

	timeOutHours = timeOutSeconds / 3600;
	timeOutSeconds = timeOutSeconds % 3600;
	timeOutMinutes = timeOutSeconds / 60;
	timeOutSeconds = timeOutSeconds % 60;

	cout << endl << endl << "Du var ute i " << timeOutHours << " timmar, " << timeOutMinutes << " minuter och " << timeOutSeconds << " sekunder." << endl;


	return 0;
}