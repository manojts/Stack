#include<bits/stdc++.h>
using namespace std;
void NSR(int arr[],int size,int right[]){
	stack<int>s;
	stack<int>sindex;
	for(int i=size-1;i>=0;i--){
		if(s.empty()){
			s.push(arr[i]);
			sindex.push(i);
			right[i] = size;
		}
		else{
			while(!s.empty() && arr[i]<=s.top()){
				s.pop();
				sindex.pop();
			}
			if(s.empty())
			{
				right[i] = size ;
			}
			else
			{
				right[i] = sindex.top();
			}
			s.push(arr[i]);
			sindex.push(i);
			
		}
	}	
}
void NSL(int arr[],int size,int left[]){
	stack<int>s;
	stack<int>sindex;
	for(int i=0;i<size;i++){
		if(s.empty()){
			s.push(arr[i]);
			sindex.push(i);
			left[i] = -1;
		}
		else{
			while(!s.empty() && arr[i]<=s.top()){
				s.pop();
				sindex.pop();
			}
			if(s.empty())
			{
				left[i] = -1 ;
			}
			else
			{
				left[i] = sindex.top();
			}
			s.push(arr[i]);
			sindex.push(i);
		}
	}

}
int main(){
	stack<int> s;
	int matrix[][4]={
		{0,1,1,0},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,0,0}
	};
	//Convert the 2d array into 1d array,
	//find the max area rectangle in each row.
	int res[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==0){
				res[i][j]=matrix[i][j];
			}
			else{
				if(matrix[i][j]!=0){
					res[i][j] = matrix[i][j]+res[i-1][j];
				}
				else{
					res[i][j]=matrix[i][j];
				}
			}
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	int right[4] = {0};
	int left[4] = {0};
	int size = 4;
	int maxArea = 0;
	for(int i=0;i<size;i++){
	NSR(res[i],size,right);
	NSL(res[i],size,left);
	int Area[size]={0};
		for(int j=0;j<size;j++){
			Area[j] =right[j]-left[j]-1;
			Area[j] = res[i][j] * Area[j];
			if(Area[j]>maxArea){
				maxArea = Area[j];
			}
		}
	}
	cout<<"Max Area of Binary Matrix "<<maxArea<<endl;


}