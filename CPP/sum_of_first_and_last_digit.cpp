/*in a number of n digit, sum of first and last digit is it's sum of oneth place digit and nth place digit

eg-
no=24362626727  - sum of first and last no = 7+2=9
no=46457473478  - sum of first and last no = 4+8=12
*/

//Code
#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){   // for multiple testcases
        long long int a;
        // if a is in order of 1e18
        cin>>a;
        int first = a%10;
        // we get the first digit 
        int last = 0;
        // we are going to start loop
        while(a>0){
            last=a%10;
            a/=10;
            // first n digit no becomes n-1 digit and so on and at last we got nth digit or last digit of number
            // further ( last digit/ 10 ) gives 0 so while loop ends
        }
        cout<< first + last <<endl; // printing the sum
    }
    return 0;
}