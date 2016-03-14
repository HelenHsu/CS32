/////////////////////////////////////////////////////////////////////////////////
// CS32 Homework3
// Problem 1
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

//Your declarations and implementations would go here

class Landmark
{
 public:
	Landmark(string name):m_name(name){};
	virtual ~Landmark(){};				//must declare a virtual destructor
	virtual string color() const{return "yellow";};	//most are yellow
	string name() const{return m_name;};		//non virtual since every name() do the same thing
	virtual string icon() const=0;			//every icon is different
 private:
	string m_name;
};

//all member function must be const,except constructor and destructor
class Hotel:public Landmark
{
 public:
	Hotel(string name):Landmark(name){};
	~Hotel(){cout<<"Destroying the hotel "<<name()<<"."<<endl;};
	virtual string icon() const{return "bed";};	
};
class Restaurant:public Landmark
{
 public:
	Restaurant(string name,int n):Landmark(name),m_n(n){};
	~Restaurant(){cout<<"Destroying the restaurant "<<name()<<"."<<endl;};
	virtual string icon() const;		//further implementation for two different icons
 private:
	int m_n;				//extra member for icons
};

string Restaurant::icon() const
{
	string temp="";
	if (m_n<40)
		temp+="small";
	else
		temp+="large";
	temp+=" knife/fork";
	return temp;
}

class Hospital:public Landmark
{
 public:
	Hospital(string name):Landmark(name){};
	~Hospital(){cout<<"Destroying the hospital "<<name()<<"."<<endl;};
	virtual string color() const{return "blue"; };		//overwrite for different colors
	virtual string icon() const{return "H";};
};


void display(const Landmark* lm)
{
    cout << "Display a " << lm->color() << " " << lm->icon() << " icon for "
         << lm->name() << "." << endl;
}


int main()
{
    Landmark* landmarks[5];
    landmarks[0] = new Hotel("Westwood Rest Good");
      // Restaurants have a name and seating capacity.  Restaurants with a
      // capacity under 40 have a small knife/fork icon; those with a capacity
      // 40 or over have a large knife/fork icon.
    landmarks[1] = new Restaurant("Bruin Bite", 30);
    landmarks[2] = new Restaurant("La Morsure de l'Ours", 100);
    landmarks[3] = new Hospital("UCLA Medical Center");
//    landmarks[4] = new Landmark("Wrong landmark");	//this will produce compilation errors
    cout << "Here are the landmarks." << endl;
    for (int k = 0; k < 4; k++)
        display(landmarks[k]);

      // Clean up the landmarks before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete landmarks[k];
}
