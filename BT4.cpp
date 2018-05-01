#include<iostream>
using namespace std;
class employee
{
	
	private:
		int num_of_employee;
		float comp;
	public:
		
		employee() :	num_of_employee(0), comp(0.0)
		{}
		employee(int number, float com)
		{
			num_of_employee = number;
			comp = com;
		}
		void set(int a, float b)
		{
			num_of_employee = a;
			comp = b;
		}
		void display()
		{
			cout << num_of_employee << endl;
			cout << comp << endl;
		}
};

int main()
{
	int i, a;
	employee p[3];
	float b;
	for(i = 0; i < 3; ++i)
	{
		cout << "Enter number of employee number " << i + 1 << ": ";
		cin >> a;
		cout << "Enter compensation of employee number " << i + 1 << ": ";
		cin >> b;
		p[i].set(a, b);
	}
	for(i = 0; i < 3; ++i)	p[i].display();
	return 0;
}
