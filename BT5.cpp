#include<iostream>
#include<windows.h>
using namespace std;
//Sai vi cho phep nhap du lieu truc tiep vao class
class date
{
	private:
		int month;
		int day;
		int year;
	public:
		void getdate()
		{
			char dummy_char;
			while(1)
			{
				system("cls");
				cout << "Enter date: ";
				cin >> month >> dummy_char >> day >> dummy_char >> year;
				if(month < 1 || month > 12)
				{
					cout << "Error input month!!" << endl;
					Sleep(1000);
					continue;
				}
				if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
					if(day < 1 || day > 31)
					{
						cout << "Error input day!!" << endl;
						Sleep(1000);
						continue;
					}
				else if(month == 2)
				{
					if(year % 4 == 0)
					{
						if(day < 1 || day > 29)
						{
							cout << "Error input day!!" << endl;
							Sleep(1000);
							continue;
						}
					}
					else
						if(day < 1 || day > 28)
						{
							cout << "Error input day!!" << endl;
							Sleep(1000);
							continue;
						}
				}
				else
				{
					if(day < 1 || day > 30)
					{
						cout << "Error input day!!" << endl;
						Sleep(1000);
						continue;
					}
				}
				if(year <= 0)
				{
					cout << "Error input year!!" << endl;
					Sleep(1000);
					continue;
				}
				break;
				system("cls");
			}
		}
		void showdate()
		{
			cout << month << "/" << day << "/" << year << endl;
		}
};
int main()
{
	date d;
	d.getdate();
	cout << "Your input date: ";
	d.showdate();
	system("pause");
	return 0;
}
