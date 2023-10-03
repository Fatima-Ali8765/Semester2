#include<iostream>
using namespace std;
class Meal{
	protected:
		string entree;
		int caloriecount;
	public:
		Meal()
		{
			entree=" ";
			caloriecount=0;
		}
		friend ostream &operator<<(ostream &,const Meal &);
		friend istream &operator>>(istream &,Meal &);
		Meal operator+(Meal &obj)
		{
			Meal temp;
			temp.caloriecount=caloriecount+obj.caloriecount;
			return temp;
		}	
};
istream &operator>>(istream &inputvariables,Meal &meal)
{
	cout<<"Enter the Entree: ";
	inputvariables>>meal.entree;
	cout<<"Enter the calorie count: ";
	inputvariables>>meal.caloriecount;
	return inputvariables;
}
ostream &operator<<(ostream &outputvariables,const Meal &meal)
{
	outputvariables<<meal.entree<<endl;
	outputvariables<<meal.caloriecount<<endl;
	return outputvariables;
}
int main()
{
	int value;
	Meal meals[21],totalcalories;
	for(value=0;value<21;value++)
	{
		cout<<value+1;
		cin>>meals[value];
	}
	for(value=0;value<21;value++)
	{
		totalcalories=totalcalories+meals[value];	
	}
	cout<<"Your calorie total at end of the week is:";
	cout<<totalcalories;
}
