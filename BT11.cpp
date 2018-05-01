#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;
class fraction
{
	private:
		int num;
		int den;
	public:
		fraction()
		{
			num = 0;
			den = 1;
		}
		fraction(int n, int d)
		{
			num = n;
			den = d;
		}
		int getnum()	{return num;}
		int getden()	{return den;}
		void setf(int a, int b)
		{
			num = a;
			if (a == 0)
				den = 1;
			else
				den = b;
		}
		void display();
		void add(fraction, fraction);
		void sub(fraction, fraction);
		void mul(fraction, fraction);
		void div(fraction, fraction);
		void lowterms();
};
int main()
{
	int a, b;
	fraction x, y, z;
	char d, cf, c;
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
		x.setf(a, b);
		x.lowterms();
		cout << "Enter fraction 2: ";
		cin >> a >> d >> b;
		if(b == 0)
		{
			cout << "The denomination must not equals 0" << endl;
			Sleep(1500);
			continue;
		}
		y.setf(a, b);
		y.lowterms();
		cout << "Addition between fraction 1 and fraction 2 is: ";
		z.add(x, y);
		z.lowterms();
		z.display();
		cout << endl;
		cout << "Subtraction between fraction 1 and fraction 2 is: ";
		z.sub(x, y);
		z.lowterms();
		z.display();
		cout << endl;
		cout << "Multiplication between fraction 1 and fraction 2 is: ";
		z.mul(x, y);
		z.lowterms();
		z.display();
		cout << endl;
		cout << "Division between fraction 1 and fraction 2 is: ";
		z.div(x, y);
		z.lowterms();
		z.display();
		cout << endl;
		cout << "\nDo you want to continue?(y/n) ";
		cin >> cf;
	}while(cf == 'y');
	system("cls");
	cout << "Thank you! See you again!" << endl;
	system("pause");
	return 0;
}
void fraction::display()
{
	if(den == 1)
		cout << num;
	else
		cout << num << '/' << den;
}
void fraction::add(fraction f1, fraction f2)
{
	num = (f1.getnum() * f2.getden()) + (f2.getnum() * f1.getden());
	den = f1.getden() * f2.getden();
	if(num == 0)
	{
		num = 0;
		den = 1;
		return;
	}
}
void fraction::sub(fraction f1, fraction f2)
{
	num = (f1.getnum() * f2.getden()) - (f2.getnum() * f1.getden());
	den = f1.getden() * f2.getden();
	if(num == 0)
	{
		num = 0;
		den = 1;
		return;
	}
}

void fraction::mul(fraction f1, fraction f2)
{
	num = f1.getnum() * f2.getnum();
	den = f1.getden() * f2.getden();
	if(num == 0)
	{
		num = 0;
		den = 1;
		return;
	}
}

void fraction::div(fraction f1, fraction f2)
{
	num = f1.getnum() * f2.getden();
	den = f1.getden() * f2.getnum();
	if(num == 0)
	{
		num = 0;
		den = 1;
		return;
	}
}

void fraction::lowterms()
{
	{
		long tnum, tden, temp, gcd;
		tnum = labs(num);
		tden = labs(den);
		if(tden==0 )
		{ cout << "Illegal fraction: division by 0"; exit(1); }
		else if( tnum==0 )
		{ num=0; den = 1; return; }
		while(tnum != 0)
		{
			if(tnum < tden) 
			{temp=tnum; tnum=tden; tden=temp;} 
			tnum = tnum - tden;
		}
		gcd = tden;
		num = num / gcd;
		den = den / gcd;
	}
}
