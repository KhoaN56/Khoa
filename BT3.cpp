#include<iostream>
using namespace std;
class time
{
	private:
		unsigned int hour;
		unsigned int min;
		unsigned int sec;
	public:
		time()
		{
			hour = 0;
			min = 0;
			sec = 0;
		}
		time(unsigned int hr, unsigned int m, unsigned int s)
		{
			hour = hr;
			min = m;
			sec = s;
		}
		int getsec(){return sec;}
		int getmin(){return min;}
		int gethour(){return hour;}
		void settime(unsigned int hr, unsigned int m, unsigned int s)
		{
//			char dummychar;
//			cin >> hour >> dummychar >> min >> dummychar >> sec;
			hour = hr;
			min = m;
			sec = s;
		}
		void display()
		{
			cout << hour << ":" << min << ":" << sec << endl;
		}
		time add(time t1) const
		{
			unsigned int a = 0, b = 0, c = 0;
			c = sec + t1.getsec();
			if(c >= 60)
			{
				b = 1;
				c -= 60;
			}
			b += (min + t1.getmin());	//Kha nang min co san gia tri -> +=
			if(b >= 60)
			{
				a = 1;
				b -= 60;
			}
			a += (hour + t1.gethour());
			if(a >= 24)
				a -= 24;
			time t(a, b, c);
			return t;
		}
};
int main()
{
	time t1(12,23,24), t2(13,24,50);
	time t3;
	t3 = t1.add(t2);
	t3.display();
	system("pause");
	return 0;
}
