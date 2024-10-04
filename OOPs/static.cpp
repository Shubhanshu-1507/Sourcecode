#include<iostream>
using namespace std;


void counter(){
  static  int count = 0 ;
    count++;
    cout<<"count "<<count<<endl;
}
void incre(){
    int i = 0;
    i++;
    cout<<i<<endl;
}
class Example{
public:
  static   int  x;
  Example(){
    cout<<"Constructor..\n";
  }
  ~Example(){
    cout<<"destructor...\n";
  }
};
int Example::x = 0;
int main(){
    // Static variables :- Variables declared as static in a function are created and intialised once for the lifetime of the program.
    // Static variable in a class are created and intialised at once. They are shared by all the objects of the class.
    counter(); // here output is 1 and 2 because we use static keyword .
    counter();
    incre(); // Here we are not using static keyword and due to it our output is 1 in both cases.
    incre();
   Example eg1;
    Example eg2;
    Example eg3;

    cout << eg1.x++ << endl;
    cout << eg2.x++ << endl;
    cout << eg3.x++ << endl;

    // Static objects :- Which is created for lifetime and just before closing the program we have to close it.
    int y = 0;
    if(y==0){
       static Example eg;
    }
    cout<<"Code ending..\n";

}