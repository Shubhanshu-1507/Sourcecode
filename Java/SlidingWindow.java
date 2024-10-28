package com.company.basic;

public class slidingwindow {
	public static void main(String[] args) {
		int arr[]= {5,10,1,88,6,10};
		int k=2 ;
		int sum=0;
		int maxm=0;
		for(int i=0;i<k;i++) {
			sum+=arr[i];
		}
		for(int i=k;i<arr.length;i++) {
			sum+=arr[i];
			sum-=arr[i-k];
			maxm=Math.max(maxm, sum);
		}
		System.out.println(maxm);*/
		
		/*int arr[]= {10,58,59,80,85,100,101};      //Linear Search
		int key=1001;
		boolean f=false;
		for(int i=0;i<arr.length;i++) {
			if(arr[i]==key) {
				f=true;
			}
		}
		System.out.println(f);
}}
