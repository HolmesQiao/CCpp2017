#include <iostream>

using namespace std;

class Clock{
	public:
		void setTime(int h, int m);
		void dispTime();
		int hT();
		int mT();
	private:
		int h, m;
};

void Clock :: setTime(int h, int m)
{
	Clock :: h = h;
	Clock :: m = m;
}

void Clock :: dispTime(void)
{
	cout << "The rescent time is: " << h << ":" << m << endl;
}

int Clock :: hT()
{
	return h;
}

int Clock :: mT()
{
	return m;
}

class AlarmClock:public Clock{
	public:
		void setAlarm(int h, int m);
		bool checkAlarm();
		void stopAlarm();
		void clearAlarm();
	private:
		int ah, am;
};

void AlarmClock :: setAlarm(int h, int m)
{
	ah = h;
	am = m;
}

bool AlarmClock :: checkAlarm()
{
//	return Clock.hT() == ah && Clock.mT() == am;
}

void stopAlarm()
{
	const int alarmLastTime = 1;
}

void AlarmClock :: clearAlarm(void)
{
	ah = am = -1;
}

int main(void)
{
	AlarmClock ac;

	for (;;){
		string cmd;

		cout << "Command list:\n\"setTime\", \"displayTime\", \"setAlarm\", \"clearAlarm\", \"quit\"\n" << endl;
		cout << "Enter the cmd: ";
		cin >> cmd;
			if (cmd == "setTime"){
				int h, m;
				cout << "Enter the time(h, m): ";
				cin >> h >> m;
				ac.setTime(h, m);
			}
			else if (cmd == "displayTime"){
				ac.dispTime();
			}
			else if (cmd == "setAlarm"){
				int h, m;
				cout << "Enter the alarm time: ";
				cin >> h >> m;
				ac.setAlarm(h, m);
			}
			else if (cmd == "clearnAlarm")
				ac.clearAlarm();
			else if (cmd == "quit")
				break;
			else
				cout << "Illegal command, input again!" << endl;
	}
}
