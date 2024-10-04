#include<iostream>
using namespace std;
class Student{
public:
    string name;
    int rollNo;
    float cgpa;
    string courseId;
    void getPercentage(){
        cout<< (cgpa*10)<<endl;
    }
};

class User{
    string password;
public:
   string name;
   string bio;
   void deactivate(){
    cout<<"Delelting account"<<endl;
   }
   void editBio(string newBio){
    bio = newBio;
    cout<<bio<<endl;
   }
   

};

// Three types of access modifiers are there.
/* 1. Private :- data and method is accessible  inside class only.
2. Public :- data and method is accessible to everyone.
3. Protected :- data and methos is accessible inside class and to its derived class.

*/
int main(){
 Student s1;
 cout<<sizeof(s1)<<endl;
 s1.name = "Saloni Saroha";
 cout<<s1.name<<endl;
 s1.cgpa = 9.39;
 cout<<s1.cgpa<<endl;
 s1.getPercentage();

 // User class
 User u1;
 u1.name = "John Doe";
 cout<<u1.name<<endl;
 u1.bio = "Passionate learner";
 cout<<u1.bio<<endl;
 u1.deactivate();
 u1.editBio("Curious about technologies");
 

}