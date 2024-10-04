#include<iostream>
using namespace std;

class Shape{
public:
virtual void draw() = 0;
};
class Circle : public Shape{
public:
void draw(){
   cout<< "draw circle\n";
}
};
class Square : public Shape{
    public:
    void draw(){
        cout<<"draw square\n";
    }
};
int main(){
    /*Abstraction :- Hiding all unnecessary details and showing only the important parts.
    1. Abstraction can be implemented by using access modifiers and abstract classes.
    2. Abstract classes are those which does not create any object.
    3. Functions which does not have any clear definition are called pure virtual function.
    4. They canont be instantiated and are meant to be inherited.
    5. Abstract classes are typically used to define an interface for derived classes.
    6. Atleast have one pure virtual function.
    */
   Circle cir1;
   cir1.draw();
   Square squ1;
   squ1.draw();
}