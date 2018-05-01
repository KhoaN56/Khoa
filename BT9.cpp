#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int MaxDivider(int a, int b)	//Tim uoc chung lon nhat
{
	int max;
	for (int i = 1; i <= (a < b? a : b); ++i)
	{
		if(a % i == 0 && b % i == 0)
			max = i;
	}
	return max;
}
class fraction
{
	private:
		int numberator;
		int denominator;
	public:
		fraction()
		{
			numberator = 0;
			denominator = 1;
		}
		set_fract(int a, int b)
		{
			numberator = a;
			denominator = b;
		}
		void show_fract();
		void sum(fraction f1, fraction f2);
};
int main()
{
	int a, b;
	fraction x, y, z;
	char d, cf;
	do
	{
		system("cls");
		cout << "Enter fraction 1: ";
		cin >> a >> d >> b;
		if(b == 0)
		{
			cout << "The denomination must not equals 0" << endl;
			Sleep(1500);
			continue;
		}
		x.set_fract(a, b);
		cout << "Enter fraction 2: ";
		cin >> a >> d >> b;
		if(b == 0)
		{
			cout << "The denomination must not equals 0" << endl;
			Sleep(1500);
			continue;
		}
		y.set_fract(a, b);
		cout << "Sum of two fractions is: ";
		z.sum(x, y);
		z.show_fract();
		cout << "Do you want to continue?(y/n) ";
		cin >> cf;
	}while(cf == 'y');
	system("pause");
	return 0;
}
void fraction::sum(fraction f1, fraction f2)	//tinh tong
{
	numberator = (f1.numberator * f2.denominator) + (f2.numberator * f1.denominator);
	denominator = f1.denominator * f2.denominator;
	if(numberator == 0)
	{
		numberator = 0;
		denominator = 1;
		return;
	}
	int shorten = MaxDivider(numberator, denominator);
	numberator /= shorten;
	denominator /= shorten;
}
void fraction::show_fract()		//xuat phan so
{
	if(denominator == 1)
		cout << numberator << endl;
	else
		cout << numberator << '/' << denominator << endl;
}
