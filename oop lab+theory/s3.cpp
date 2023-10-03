#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Product{
	private:
		long long int barcode;
		string name;
	public:
		Product(long long int b=0,string n=""):barcode(b),name(n)
		{
		}
		void setCode(long long int x){
		barcode=x;	
		}
		long long getCode(){
		return barcode;	
		}
		void setName(string t){
			name=t;
		}
		string getName(){
			return name;
		}
		void scanner(){
			cout<<"\nBarcode: ";
			cin>>barcode;
			cout<<"\nName: ";
			cin>>name;
		}
		void printer(){
			cout<<"\nBarcode: ";
			cout<<barcode;
			cout<<"\nName: ";
			cout<<name;
		}
};
class PrepackedFood:public Product
{
	private:
		float priceperuni;
	public:
		FreshFood(float q=0,long long int k=0,string var=""):
		Product(k,var),priceperuni(q){
		}
		void setPrice(float val){priceperuni=val;}
		float getPrice(){return priceperuni;}
		void scanner()
		{Product::scanner();
		cout<<"Price per unit: "<<priceperuni<<endl;
		}
		void printer()
		{Product::printer();
		cout<<fixed<<setprecision(2)<<"Price per unit: "<<priceperuni<<endl;
		}
};
//class FreshFood:public Product{
//	private:
//		float weight;
//		float current_price_per_kilo;
//	public:
//		FreshFood(float w=0,float currentperkilo=0,long long int k=0,string var=""):
//		Product(k,var),weight(w),current_price_per_kilo(currentperkilo)	
//		{
//		}
//		void setweight(float ol){weight=ol;}
//		float getweight()
//		{
//			return weight;
//		}
//		void setprice(float al){current_price_per_kilo=al;}
//		float getprice(){
//			return current_price_per_kilo;
//		}
//		void scanner()
//		{Product::scanner();
//		cout<<"Weight(kilo): ";
//		cin>>weight;
//		cout<<"Price/kilo: ";
//		cin>>current_price_per_kilo;
//		}
//		void printer()
//		{Product::printer();
//		cout<<fixed<<setprecision(2)<<"\nPrice per kilo: "<<current_price_per_kilo<<"\nWeight: "<<weight<<"\nTotal: "<<current_price_per_kilo*weight<<endl;
//		}
//};
int main()
{
	Product p1(12345,"Flour"),p2;
	p1.printer();
	p2.setName("Sugar");
	p2.setCode(543221);
	p2.printer();
	PrepackedFood pf1(0.49,23456,"Salt"),pf2;
	pf1.printer();
	cout<<"\nInput data of prepacked product: ";
	pf2.scanner();
	pf2.printer();
//	FreshFood pu1(1.5,1.69,45678,"Grapes"),pu2;
//	pu1.printer();
//	cout<<"\nInput data of fresh product: ";
//	pu2.scanner();
//	pu2.printer();
}
