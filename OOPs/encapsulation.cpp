#include<iostream>
using namespace std;

class temp{
     int a;
  int b;
  public:
  int solve(int input){
    a=input;
    b=a/2;
    return b;
  }
};
int main(){
    // Encapsulation is the process of wrapping up of data and member functions into a single module/unit. It also implements data hiding.
     int n;
  cin>>n;
  temp half;
  int ans=half.solve(n);
  cout<<ans<<endl;
}