#include <iostream>
using namespace std;
class Location{
	private:
		int latitude,longitude;
	public:
		Location(int Latitude=0,int Longitude=0){
			latitude=Latitude;
			longitude=Longitude;
		}
		virtual void Display()const{
			cout<<"Latitude: "<<latitude<<endl;
			cout<<"Longitude: "<<longitude;
		}
		Location &operator++(){
			latitude++;
			longitude++;
			return *this;
		}
		Location operator++(int){
			Location templocation=*this;
			latitude++;
			longitude++;
			return templocation;
		}
		Location operator+(int x)const
		{
			Location templocation;
			templocation.latitude=latitude+x;
			templocation.longitude=longitude+x;
			return templocation;
		}
		friend Location operator+(int value,const Location &location);
};
Location operator+(int value,const Location &location)
{
	Location templocation;
	templocation.latitude=location.latitude+value;
	templocation.longitude=location.longitude+value;
	return templocation;
}
class Details: public Location{
	private:
		string address;
	public:
		Details(string Address=""){
			address=Address;
		}
		virtual void Display()const
		{
			cout<<endl<<"Address: "<<address;
		}
};
int main()
{
	Details details("Lahore");
	Location obj1(10,20),obj2(5,30),obj3(90,90);
	cout<<endl<<"Location of obj1: ";
	obj1.Display();
	cout<<endl<<"Location of obj2: ";
	obj2.Display();
	cout<<endl<<"Location of obj3: ";
	obj3.Display();
	details.Display();
	++obj1;
	cout<<endl<<"Preincrement result of obj1: "<<endl;
	obj1.Display();
	obj2=obj1++;
	cout<<endl<<"Postincrement result of obj1: "<<endl;
	obj2.Display();
	obj2=obj1+10;
	cout<<endl<<"(keeping 10 the operand on right hand side),the result for obj2\n";
	obj2.Display();
	obj2=10+obj1;
	cout<<endl<<"(keeping 10 the operand on left hand side),the result for obj2\n";
	obj2.Display();
	obj1=obj2=obj3;
	cout<<endl<<"Location of obj1: \n";
	obj1.Display();
	cout<<endl<<"Location of obj2: \n";
	obj2.Display();
	cout<<endl<<"Location of obj3: \n";
	obj3.Display();
	cout<<"Address through pointer:\n";
	Location *point1;
	point1=&details;
	point1->Display();
	return 0;
}
