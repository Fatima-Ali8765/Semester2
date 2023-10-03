#include<iostream>
using namespace std;
class Numdays{
	private:
		float hours;
		float days;
	public:
		Numdays(float num=0)
		{
			sethour(num);
		}
		void sethour(float number)
		{
			hours=number;
		}
		void setdays()
		{
			days=hours/8.0;
		}
		float getdays()
		{
			return days;
		}
		float gethours()
		{
			return hours;
		}
		Numdays &operator++()
		{
			hours++;
			return *this;
		}
		Numdays operator++(int)
		{
			Numdays temp=*this;
			hours++;
			return temp;
		}
		Numdays &operator--()
		{
			hours--;
			return *this;
		}
		Numdays operator--(int)
		{
			Numdays temp=*this;
			hours--;
			return temp;
		}
		Numdays operator+(Numdays nd)
		{
			Numdays temp;
			temp.hours=hours+nd.hours;
			return temp;
		}
		Numdays operator-(Numdays nd)
		{
			Numdays temp;
			temp.hours=hours-nd.hours;
			return temp;
		}
};
int main()
{
	Numdays numberofdays1;
	float hours;
	cout<<"Enter the number of hours for object 1: ";
	cin>>hours;
	Numdays X(hours);
	cout<<"Enter the number of hours for object 2: ";
	cin>>hours;
	Numdays Y(hours);
	X.setdays();
	cout<<"Original hour of object 1 is converted into days: "<<endl;
	cout<<X.getdays();
	Y.setdays();
	cout<<endl<<"Original hour of object 2 is converted into days: "<<endl;
	cout<<Y.getdays();
	cout<<endl<<"Adding the hour of object 1 and object 2: ";
	numberofdays1=X+Y;
	numberofdays1.setdays();
	cout<<endl<<"Addition of hours of object 1 and object 2 and convertind it into days: "<<endl;
	cout<<numberofdays1.getdays();
	cout<<endl<<"Subtracting the hours of object 1 and object 2: ";
	if(X.gethours()>Y.gethours())
		numberofdays1=X-Y;
	else
		numberofdays1=Y-X;
	numberofdays1.setdays();
	cout<<endl<<"Subtraction of hours of object 1 and object 2 and convertind it into days: "<<endl;
	cout<<numberofdays1.getdays();
	numberofdays1=++X;
	numberofdays1.setdays();
	cout<<endl<<"Hour prefix incremented and converted into days: "<<endl;
	cout<<numberofdays1.getdays();
	
	numberofdays1=X++;
	numberofdays1.setdays();
	cout<<endl<<"Hour postfix incremented and converted into days: "<<endl;
	cout<<numberofdays1.getdays();

	numberofdays1=--X;
	numberofdays1.setdays();
	cout<<endl<<"Hour prefix decremented and converted into days: "<<endl;
	cout<<numberofdays1.getdays();

	numberofdays1=X--;
	numberofdays1.setdays();
	cout<<endl<<"Hour postfix decremented and converted into days: "<<endl;
	cout<<numberofdays1.getdays();
}
