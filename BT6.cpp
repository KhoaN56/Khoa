#include<iostream>
#include<conio.h>
#include<windows.h>
#include <mylib.h>
#include"Mylib.h"
using namespace std;
class date
{
	//Sai vi cho phep nguoi dung nhap du lieu truc tiep vao class
	private:
		int month;
		int day;
		int year;
	public:
		void getdate()
		{
			char dummy_char;
			cin >> month >> dummy_char >> day >> dummy_char >> year;
		}
		void showdate()
		{
			cout << month << "/" << day << "/" << year << endl;
		}
};
enum etype{
	laborer, secretary, manager, accountant, executive, researcher 
};
char etype_c[6][11] = {"laborer", "secretary", "manager", "accountant", "executive", "researcher"};
class employee
{
	
	private:
		date first_employment;
		static int em_num;
		float compensation;
		etype type;
	public:
		
		employee(){};
		employee(float com)
		{
			em_num++;
			compensation = com;
		}
		void getemployee(char tp, date fd)
		{
			switch(tp)
			{
				case 'l':
					type = laborer;
					break;
				case 's':
					type = secretary;
					break;
				case 'm':
					type = manager;
					break;
				case 'a':
					type = accountant;
					break;
				case 'e':
					type = executive;
					break;
				case 'r':
					type = researcher;
					break;
			}
			first_employment = fd;
		}
		void display_em_num()
		{
			cout << etype_c[em_num] << endl;
		}
		void display_rest()
		{
			cout << compensation << endl;
			cout << etype_c[type] << endl;
			first_employment.showdate();
		}
};
int employee::em_num = 0;
int main()
{
	int x, y;
	char c;
	employee p1(27.3);
	date fd;
	cout << "Enter hired date: ";
	fd.getdate();
	cout << "Enter employee's type: ";
	x = wherex() + 1;
	y = wherey() + 1;
	do
	{
		c = getche();
		if(c != 'l' && c != 's' && c != 'm' && c != 'a' && c != 'e' && c != 'r')
		{
			cout << "\nInput must be in one of these charaters: l, s, a, m, e, r" << endl;
			Sleep(2000);
			xoadong(y, 4, x);
		}
	}while(c != 'l' && c != 's' && c != 'm' && c != 'a' && c != 'e' && c != 'r');
	cout << endl;
	p1.getemployee(c, fd);
	p1.display_rest();
	system("pause");
	return 0;
}
