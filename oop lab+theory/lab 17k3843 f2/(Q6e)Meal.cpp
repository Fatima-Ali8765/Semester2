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
	Meal breakfast,lunch,dinner,totalcalories;
	cout<<"data entry of breakfast : \n";
	cin>>breakfast;
	cout<<"data entry of lunch : \n";
	cin>>lunch;
	cout<<"data entry of dinner : \n";
	cin>>dinner;
	totalcalories=breakfast+lunch+dinner;
	cout<<"Breakfast:\n";
	cout<<breakfast;
	cout<<"Lunch:\n";
	cout<<lunch;
	cout<<"Dinner:\n";
	cout<<dinner;
	cout<<"\nYour total calorie count is:";
	cout<<totalcalories;
}
