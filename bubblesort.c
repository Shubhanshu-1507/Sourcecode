#include <stdio.h>
#include <stdlib.h>
int main(){

   int n;

   printf("Enter the number of elements :  ");
   scanf("%d",&n);

   int *arr = (int *)malloc(n * sizeof(int));

   printf("Enter the elements : \n");
   for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
   }


    for(int i=0;i<n-1;i++){
        int swapped=0;
        for(int j=0;j<9-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;

            }
            
           
        }
        if(swapped==0){
            break;
        }
         
    }
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) 
        printf("%d \n", arr[i]);


    return 0;
}