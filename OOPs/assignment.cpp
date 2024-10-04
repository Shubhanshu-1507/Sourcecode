#include<iostream>
using namespace std;

// 1 question:-
class BankAccount{
 int accountNumber;
  float balance;
 public:
 void deposit(){
    cout<<"Deposited amount\n";
 }
 void withdraw(){
    cout<<"Withdraw amount\n";
 }
 void getbalance(){
    cout<<"Balance money\n";
 }
 BankAccount(int accountNumber, float balance){
    this->accountNumber = accountNumber;
    this->balance = balance;
 }

int getaccountNumber(){
    return accountNumber;
 }
 float getBalance(){
    return balance;
 }

};
// 2 question:-

class Person{
protected:
string name;
int age;
public:
Person(string n, int a){
    name = n;
    age = a;
}
};
class Student : public Person{
private:
string studentID;
public:
Student(string n, int a, string id):Person(n,a){
    studentID = id;
}
void displayStudentInfo(){
    cout<< "name : "<< this->name<<endl;
    cout<< "age : "<<this->age<<endl;
    cout<< "studentId :"<<this->studentID<<endl;
}
};
int main(){
BankAccount b1(10985674,10200.789);
b1.deposit();
b1.withdraw();
b1.getbalance();
cout<<b1.getBalance()<<endl;
cout<<b1.getaccountNumber()<<endl;

Student student("Alice", 20, "S12345");
student.displayStudentInfo();

}