// Problem statement
// You have been given two sorted arrays/lists(AR1 and AR2) of size N and M respectively, merge them into a third array/list such that the third array is also sorted.

// Note:
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^5
// 0 <= M <= 10^5
// Time Limit: 1 sec
// Note:
// Consider the case when size of the two arrays is not same.
// Sample Input 1 :
// 1
// 5
// 1 3 4 7 11
// 4
// 2 4 6 13
// Sample Output 1 :
// 1 2 3 4 4 6 7 11 13
// Sample Input 2 :
// 2
// 3
// 10 100 500
// 7
// 4 7 9 25 30 300 450
// 4
// 7 45 89 90
// 0
// Sample Output 2 :
// 4 7 9 10 25 30 100 300 450 500
// 7 45 89 90

// C++

#include <bits/stdc++.h>
using namespace std;

int* merge2SortedArrays(int ar1[], int n1, int ar2[], int n2){
    int* ar3 = new int[n1 + n2];
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n1 && j < n2){
        if(ar1[i] <= ar2[j]){
            ar3[k] = ar1[i];
            i++;
            k++;
        }else{
            ar3[k] = ar2[j];
            j++;
            k++;
        }
    }
    while(i < n1){
        ar3[k] = ar1[i];
        i++;
        k++;
    }
    while(j < n2){
        ar3[k] = ar2[j];
        j++;
        k++;
    }
    return ar3;
}

void printArray(int ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ar[i];
	}
}

int main()
{
	int ar1[] = {1, 4, 8, 10, 13, 17};
	int m = sizeof(ar1) / sizeof(ar1[0]);
	int ar2[] = {2, 3, 5, 7, 9, 11, 12};
	int n = sizeof(ar2) / sizeof(ar2[0]);
	int k = m+n;
	int* ar3 = merge2SortedArrays(ar1, m, ar2, n);
	printArray(ar3,k);
	return 0;
}

// Java

// public class Merge2SortedArrays {
// public static void printArray(int[]arr){
//     int n=arr.length;
//     for(int i=0;i<n;i++){
//         System.out.println(arr[i]);
//     }
// }
// public static int[] merge2SortedArrays(int[] ar1,int[]ar2){
//     int m=ar1.length;
//     int n=ar2.length;
//     int[] arr=new int[m+n];
//     int i=0;
//     int j=0;
//     int k=0;
//     while(i<m && j<n){
//         if(ar1[i]<=ar2[j]){
//             arr[k]=ar1[i];
//             i++;
//             k++;
//         }else{
//             arr[k]=ar2[j];
//             j++;
//             k++;
//         }
//     }
//     while(i<m){
//         arr[k]=ar1[i];
//         i++;
//         k++;
//     }
//     while(j<n){
//         arr[k]=ar2[j];
//         j++;
//         k++;
//     }
//     return arr;
// }

// public static void main(String args[]) {
//     int ar1[]={1,4,8,10,13,17};
//     int ar2[]={2,3,5,7,9,11,12};
//     int ar3[]=merge2SortedArrays(ar1,ar2);
//     printArray(ar3);
//     }
// }