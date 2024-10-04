#include<iostream>
using namespace std;

class Company{
int eid;
float esalary;
public:
void getSalary(float salary){
    cout<<salary<<endl;
}
void bonus(){
    cout<<"It depends on your progress";
}
// Setters
void setEid(int Id){
    eid = Id;
}

void setSalary(float varSalary){
    esalary = varSalary;

}

// Getters
int getId(){
    return eid;
}
float getSalary(){
    return esalary;
}

};
int main(){
Company c1;
c1.setEid(12345678);
c1.setSalary(10000.00);
cout<<c1.getId()<<endl;
cout<<c1.getSalary()<<endl;
}