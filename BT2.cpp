#include<iostream>
#include<windows.h>
#include<mylib.h>
#include "Mylib.h"
using namespace std;
const int ESC = 27;
class tollBooth
{
	private:
		static unsigned int cars;
		static double money;
	public:
		tollBooth()
		{
			cars = 0;
			money = 0;
		}
		void payingCar()
		{
			cars++;
			money += 0.5;
		}
		void nopayCar()
		{
			++cars;
		}
		void display_cars()
		{
			cout << cars;
		}
		void display_money()
		{
			cout << money;
		}
};
unsigned int tollBooth::cars = 0;
double tollBooth::money = 0;
int main()
{
	tollBooth booth;
	char key;
	int x1, y1, x2, y2;
	cout << "Number of cars: ";	
	x1 = wherex() + 1;
	y1 = wherey() + 1;
	cout << "\nMoney paid: ";
	x2 = wherex() + 1;
	y2 = wherey();
	gotoxy(x1, y1);
	do
	{
		key = getch();
		switch(key)
		{
			case 0:
				key = getch();
				break;
			case 'o':
				booth.payingCar();
				gotoxy(x1, y1);
				booth.display_cars();
				xoadong(2, 2, x2);
////				gotoxy(x2, y2);
				booth.display_money();
				break;
			case 'x':
				booth.nopayCar();
				gotoxy(x1, y1);
				booth.display_cars();
				break;
			case ESC:
				break;
			default:
				gotoxy(1, 3);
				cout << "Press \"x\"\ when a car did not paid, \"o\"\ when a car did and ESC to end program!!" << endl;
				Sleep(1500);
				xoadong(3, 2);
				break;
		}
		
	}while(key != ESC);
	gotoxy(1, 3);
	cout << "Thank you for using this program! See you again!" << endl;
	system("pause");
	return 0;
}
