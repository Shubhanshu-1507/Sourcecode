//  Problem Statement: Given an integer numRows, return the first numRows of Pascal's triangle. In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:



//                                     1
//                                 /       \
//                                 1       1
//                             /      \ /      \
//                             1       2       1
//                         /      \ /     \ /      \
//                         1       3       3       1
//                     /      \ /     \ /      \ /     \       
//                     1       4       6        4      1


//Answer: 

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int numRows;                                                        // take user input for number of rows required in Pascal's triangle
    cin>>numRows;

    vector<vector<int>> ans;                                            // creating an answer vector to store the triangle

    for(int i = 0; i<numRows; i++){
        ans.push_back(vector<int>());                                   // creating a new row in answer array
        for(int j= 0; j<=i;j++){
            if(j==0 || j==i)ans[i].push_back(1);                        // if it is the first or last position, fill-in 1 in the row
            else{
                ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);          // else calculate the sum from the previous array
            }
        }
    }



// Printing the rows of Pascal's Triangle

    for (auto i : ans){
        cout<<"[ ";
        for (auto j : i){
             cout<<j<<" ";
        }
        cout<<"]";

        cout<<endl;
    }
    return 0;
}
