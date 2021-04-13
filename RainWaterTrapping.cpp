/*
Find the max element to right of arr[i].
Find the max element to left of arr[i].
result = min(right[i],left[i])-arr[i]
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {3,0,2,0,2};
	int len = 5;
	int left[5]={0};
	int right[5]={0};
	int total = 0;
	for(int i=0;i<len;i++){
		if(i==0){
			left[i]=arr[i];
		}
		else if(left[i-1]>arr[i]){
			left[i]=left[i-1];
		}
		else{
			left[i]=arr[i];
		}
	}
	for(int i=len-1;i>=0;i--){
		if(i==len-1){
			right[i]=arr[i];
		}
		else if(right[i+1]>arr[i]){
			right[i]=right[i+1];
		}
		else{
			right[i]=arr[i];
		}
		total += min(right[i],left[i])-arr[i];
	}
	cout<<total<<endl;


}