#include <iostream>
using namespace std;
class Int
{
	private:
		int num;
	public:
		Int()
		{
			num = 0;
		}
		Int(int number)
		{
			num = number;
		}
		void setnum(int x);
		int getnum()
		{
			return num;
		}
		Int add(Int);
//		~Int(){
//			cout << "Da huy!" << endl;
//			}
};
void Int::setnum(int x)
{
	num = x;
}
Int Int::add(Int num1)
{
	return (num + num1.getnum());
}

int main()
{
	int a, b, c;
	Int num1, num2, sum;
	cout << "Enter first number: ";	cin >> a;
	num1.setnum(a);
	cout << "Enter second number: ";	cin >> b;
	num2.setnum(b);
	sum = num1.add(num2);
	cout << "Result of addition between two number: " << sum.getnum() << endl;
	system("pause");
	return 0;
}
