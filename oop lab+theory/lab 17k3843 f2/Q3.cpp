#include <iostream>
using namespace std;
class Time{
	private:
		int hours,minutes,seconds;
	public:
		Time(int h=0,int m=0,int s=0)
		{
			hours=h;
			minutes=m;
			seconds=s;
		}
		void printTime()
		{
			cout<<"Hours: "<<hours<<endl;
			cout<<" Minutes: "<<minutes<<endl;
			cout<<" Seconds: "<<seconds<<endl;
		}
		Time operator+(Time &time){
		Time temp;
		if((seconds+time.seconds)>=60 && (minutes+time.minutes)>=60)
		{
		temp.seconds=seconds+time.seconds-60;
		temp.minutes=minutes+time.minutes-60+1;
		temp.hours=hours+time.hours+1;
		}
		if((minutes+time.minutes)>=60)
		{
		temp.seconds=seconds+time.seconds;
		temp.minutes=minutes+time.minutes-60;
		temp.hours=hours+time.hours+1;
		}
		if((seconds+time.seconds)>=60)
		{
		temp.seconds=seconds+time.seconds-60;
		temp.minutes=minutes+time.minutes+1;
		temp.hours=hours+time.hours;
		}
		else
		{
			temp.seconds=seconds+time.seconds;
		temp.minutes=minutes+time.minutes;
		temp.hours=hours+time.hours;
		}
		return temp;
		}
		bool operator<(Time &object)
	{
		bool temp=true;
		if(hours<=object.hours && seconds<=object.seconds && minutes<=object.minutes)
		{
		return true;
	}
	else 
	return false;
		
	}
};
int main()
{
	int h1,h2,m1,m2,s1,s2;
	cout<<"Enter time for first object: ";
	cin>>h1;
	cin>>m1;
	cin>>s1;
	cout<<"Enter time for first object: ";
	cin>>h2;
	cin>>m2;
	cin>>s2;
	Time obj1(h1,m1,s1),obj2(h2,m2,s2);
	Time time;
	cout<<"time of obj1:\n";
	obj1.printTime();
	cout<<"time of obj2:\n";
	obj2.printTime();
	time=obj1+obj2;
	cout<<"Time:\n";
	time.printTime();
	if(obj1<obj2)
	{
		cout<<"Time 1 is low and the time is "<<endl;
		obj1.printTime();
	}
	if(obj2<obj1)
	{
		cout<<"Time 2 is low and the time is "<<endl;
		obj2.printTime();
	}
}
