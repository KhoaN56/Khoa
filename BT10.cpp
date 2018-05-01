#include<iostream>
#include<windows.h>
#include<mylib.h>
#include"Mylib.h"
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
			minutes = 0.0;
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
			cout << ang << '\xF8' << minutes << "'" << dir;
		}
};
class ship
{
	private:
		static unsigned int count;
		unsigned int serial_num;
		angle longitude, latitude;
	public:
		ship()
		{
			++count;
			serial_num = count;
		}
		void input_pos(angle longi, angle lati)
		{
			longitude = longi;
			latitude = lati;
		}
		void report()
		{
			cout << "Number of ship is: " << serial_num << endl;
			cout << "Coordinate of ship is: "; 
			longitude.show_angle(); cout << " , "; latitude.show_angle();
			cout << endl;
		}
};
unsigned int ship::count = 0;
int main()
{
	char d;
	int a, x, y, i;
	float m;
	ship s[3];
	angle co1, co2;
	for(i = 0; i < 3; ++i)
	{
		cout << "Ship " << i + 1 << endl;
		cout << "----Input longitude----" << endl;
		cout << "Input angle: ";
		cin >> a;
		cout << "Input minutes: ";
		cin >> m;
		cout << "Input direction: ";
		x = wherex() + 1;
		y = wherey() + 1;
		do
		{
			xoadong(y, 2, x);
			cin >> d;
			switch(d)
			{
				case 'w':
					d = 'W';
					break;
				case 'W':
					break;
				case 'e':
					d = 'E';
					break;
				case 'E':
					break;
				default:
					cout << "Longitude's direction must be West or East!!";
					Sleep(1500);
					break;
			}
		}while(d != 'w' && d != 'W' && d != 'e' && d != 'E');
		co1.set_angle(a, m, d);
		cout << "----Input latitude----" << endl;
		cout << "Input angle: ";
		cin >> a;
		cout << "Input minutes: ";
		cin >> m;
		cout << "Input direction: ";
		x = wherex() + 1;
		y = wherey() + 1;
		do
		{
			
			xoadong(y, 2, x);
			cin >> d;
			switch(d)
			{
				case 's':
					d = 'S';
					break;
				case 'S':
					break;
				case 'n':
					d = 'N';
					break;
				case 'N':
					break;
				default:
					cout << "Longitude's direction must be South or North!!";
					Sleep(1500);
					break;
			}
		}while(d != 's' && d != 'S' && d != 'n' && d != 'N');
		co2.set_angle(a, m, d);
		s[i].input_pos(co1, co2);
		system("cls");
	}
	s[i--].report();
	s[i--].report();
	s[i].report();
	system("pause");
	return 0;
}
