#include <iostream>
using namespace std;
class PrimeNumber{
	private:
		int number;
	public:
		PrimeNumber()
		{
			number=1;
		}
		PrimeNumber(int x)
		{
			number=x;
		}
		int getprime()
		{
			return number;
		}
		
		PrimeNumber operator++(int){
			int nextprime=number;
			do{
				nextprime++;
			}while(!isPrime(nextprime));
			return PrimeNumber(nextprime);
		}
		
		PrimeNumber operator--(int){
			int previousprime=number;
			do{
				previousprime--;
				if(previousprime<1)
				{return PrimeNumber(1);
				}
			}while(!isPrime(previousprime));
			return PrimeNumber(previousprime);
		}
		bool isPrime(int num);
};
bool PrimeNumber::isPrime(int num){
			for(int value=num-1;value>1;value--)
			if(num%value==0)
			return false;
			return true;
		}
int main()
{
	PrimeNumber prime1(13),p2;
	cout<<"Initial values:\n";
	cout<<prime1.getprime()<<endl;
	cout<<p2.getprime()<<endl;
	PrimeNumber p3=p2++;
	cout<<"Value of prime3:\n";
	cout<<p3.getprime()<<endl;
	PrimeNumber p4=prime1++;
	cout<<"Value of prime4:\n";
	cout<<p4.getprime()<<endl;
	PrimeNumber p5=prime1--;
	cout<<"Value of prime5:\n";
	cout<<p5.getprime()<<endl;
}
