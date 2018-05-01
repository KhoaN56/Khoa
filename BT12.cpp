#include<iostream>
#include<mylib.h>
#include<iomanip>
using namespace std;
class fraction
{
	private:
		int num;
		int den;
	public:
		fraction()	:	num(0), den(1)
		{}
		fraction(int n, int d)	:	num(n), den(d)
		{}
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
	int a, i, j;
	fraction f1;
	cout << "Enter denomination: ";
	cin >> a;
	fraction multiply[a - 2];
	gotoxy(7, 2);
	for(i = 0; i < a - 1; ++i)
	{
		multiply[i].setf(i+1, a);
		multiply[i].lowterms();
		multiply[i].display();
	}
	cout << endl;
	for(i = 0; i < a; ++i)	cout << "-------";
	cout << endl;
	for(i = 0; i < a - 1; ++i)
	{
		multiply[i].display();
		for(j = 0; j < a - 1; ++j)
		{
			f1.mul(multiply[i], multiply[j]);
			f1.lowterms();
			f1.display();
		}
		cout << endl;
	}
	return 0;
}
void fraction::display()
{
	if(den == 1)
		cout << num;
	else
		cout << setw(den<10?5:4) << num << '/' << den;
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
