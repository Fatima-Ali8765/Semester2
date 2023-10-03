#include <iostream>
using namespace std;
class PhoneCall{
	private:
		long long int phonenumber;
		int call_length;
		int rateperminute;
	public:
		PhoneCall(long long int Phonenumber=0,int Calllength=0,int Rateperminute=0){
		phonenumber=Phonenumber;
		call_length=Calllength;
		rateperminute=Rateperminute;			
		}
		bool operator==(PhoneCall &obj)
		{
			if(phonenumber==obj.phonenumber)
			return true;
			else 
			return false;
		}
		friend ostream &operator<<(ostream &,const PhoneCall &);
		friend istream &operator>>(istream &,PhoneCall &);
};
ostream &operator<<(ostream &output,const PhoneCall &call){
	output<<"Phone number: "<<call.phonenumber<<"\nCall Length: "<<call.call_length<<"\nRate per minute: "<<call.rateperminute;
	return output;
}
istream &operator>>(istream &input,PhoneCall &call)
{
input>>call.phonenumber;
input>>call.call_length;
input>>call.rateperminute;
return input;
} 
int main()
{
	PhoneCall list[10];
	int firstloop,secondloop;
	bool isCall;
	for(firstloop=0;firstloop<10;firstloop++)
	{
		do{
		cout<<"\n"<<firstloop+1<<".Enter the details in the following order: \n A.Phone number\n B.Call Length\n C.Rate perminute\n";
		cin>>list[firstloop];
		isCall=false;
		for(secondloop=0;secondloop<10;secondloop++)
		{
		if(secondloop!=firstloop)
		if(list[firstloop]==list[secondloop])
			{
			isCall=true;
			cout<<"The entered phone number is already registered\n----------------------\n";
			}
		}
		}while(isCall);
	}
	for(firstloop=0;firstloop<10;firstloop++){
	cout<<firstloop+1<<"\n"<<list[firstloop];
	cout<<"\n"<<"--------------------------------------------------------------\n";
	}
}
