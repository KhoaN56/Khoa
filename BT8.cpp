#include<iostream>
using namespace std;
class serial
{
	private:
		static unsigned int count;
		unsigned int serial_code;
	public:
		serial()
		{
			++count;
			serial_code = count;
		}
		void report()
		{
			cout << "I am number " << serial_code << endl;
		}
};
unsigned int serial::count = 0;
int main()
{
	serial x1, x2, x3;
	x1.report();
	x2.report();
	x3.report();
	system("pause");
	return 0;
}
