#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
class angle
{
	private:
		int ang;
		float minutes;
		char dir;
	public:
		angle()
		{
			ang = 0;
			minutes = 0;
			dir = 0;
		}
		void set_angle(int a, float m, char d)
		{
			ang = a;
			minutes = m;
			dir = d;
		}
		void show_angle()
		{
			cout << ang << '\xF8' << minutes << "'" << dir << endl;
		}
};
int main()
{
	char cf, d;
	int a;
	float m;
	angle x;
	do
	{
		system("cls");
		cout << "Enter angle: ";
		cin >> a;
		cout << "Enter minutes: ";
		cin >> m;
		if (m < 0)
		{
			cout << "Minute must not be a negative!!";
			Sleep(1500);
			continue;
		}
		if(m > 60)
		{
			cout << "Minute must smaller than 60!!";
			Sleep(1500);
			continue;
		}
		cout << "Enter direction: ";
		cin >> d;
		if(d != 'W' || d != 'E' || d != 'S' || d != 'N' 
		|| ((d == 'S' || d == 'N') && (a < 0 || a >90)) 
		|| ((d == 'E' || d == 'W') && (a < 0 || a >180)))
		{
			cout << "Cordinate entered is not available!! Please try again!!";
			Sleep(1500);
			continue;
		}
		x.set_angle(a, m, d);
		cout << "Your coordinate: ";
		x.show_angle();
		cout << "Do you want to try again?(y/n) ";
		cin >> cf;
	}while(cf == 'y');
	system("pause");
	return 0;
}
