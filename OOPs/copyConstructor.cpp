#include<iostream>
using namespace std;

// shallow copy and deep copy
class Car{
    public:
        string name;
        string color;
        int *mileage;
        Car(string name, string color){
            this->name = name;
            this->color = color;
            mileage = new int;
            *mileage = 12;
        }
        Car(Car &original){
            cout<<"Copying original to new...\n";
            name = original.name;
            color = original.color;
            mileage = original.mileage;
        }
        ~Car(){
            cout<<"deleting objects\n";
            if(mileage!=NULL){
                delete mileage;
                mileage = NULL;
            }
        }


};
int main(){
Car c1("Mercedes benz", "white");
Car c2(c1);
cout<<c2.color<<endl;
cout<<c2.name<<endl;
cout<<*c2.mileage<<endl;
*c2.mileage = 10;
cout<<*c1.mileage<<endl;
}