#include<iostream>
using namespace std;
class Car{
    string name;
    string color;
public:
Car(){
    cout<<"These are non-parametrized constructor or default constructor"<<endl;
}

// parametrized constructor are used for initilization purpose.
// constructor overloading is when we use same constructor but with different parametres.
Car(string nameVal, string colorVal){
    cout<<"Welcome to the constructor."<<endl;
    name = nameVal;
    color = colorVal;
}

// Made constructor by using this .
// this keyword is used for pointing the current object.
Car(string name, string color){
    cout<<"Parametrized constructor."<<endl;
    this->name = name;
    this->color = color;
}

string getName(){
    return name;
}
string getColor(){
    return color;
}
void stop(){
    cout<<"This function is used for stop the car"<<endl;
}
void start(){
    cout<<"This function is used for starting the car"<<endl;
}

};
int main(){
    /*  Constructors are special methods invoked automattically at the time of object creation.
    1. Same as class name.
    2.It does not have any return type.
    3. Invoked automatticaaly only at once.
    4. memory allocation happened when constructor is called.
    */
   Car c0;
   Car c1("Mercedes Benz", "White");
   cout<<c1.getName()<<endl;
   cout<<c1.getColor()<<endl;

   cout<<c1.getName()<<endl;

   return 0;
}