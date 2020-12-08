#include <bits/stdc++.h>
using namespace std;
/*
printing the element greater the element towards its right
	Traverse through the array
		if the stack is empty
			push(i)
		if the arr[i] is less the top of stack
			push(i)
		if the arr[i] is greater than top of stack ,


arr[]={1,0,2,4,3,6};
output: 2 2 4 6 6 -1


printing the element greater the element towards its left
arr[]={1,0,2,4,3,6};
output: -1 1 -1 -1 4 -1
*/
class Stack{
	public:
		int top;
		int arr[50];

		void push(int data){
			arr[++top]=data;
		}

		int pop(){
			return arr[top--];
		}
	};

void PrintGreaterToRight(Stack s,int arr[],int size){


	int res[size] = {-1};
	for(int i=0;i<size;i++)
	{
		if(s.top==-1)
		{
			s.push(i);
		}
		else if(arr[i]<=s.arr[s.top])
		{
			s.push(i);
		}
		else
		{
			while( arr[i] > s.arr[s.top] && s.top >-1 ){
			res[s.pop()] = arr[i];
			//s.pop();
		}
			s.push(i);
		}
	}
	for(int i=0;i<=s.top;i++){
		res[s.arr[i]]=-1;
	}
	for(int i=0;i<size;i++){
		cout<<res[i]<<" ";
	}
}
void PrintSmallerToRight(Stack s,int arr[],int size){
	int res[size] = {-1};
	for(int i=0;i<size;i++)
	{
		if(s.top==-1)
		{
			s.push(i);
		}
		else if(arr[i]>s.arr[s.top])
		{
			s.push(i);
		}
		else
		{
			while( arr[i] <= s.arr[s.top] && s.top >-1 ){
			res[s.pop()] = arr[i];
		}
			s.push(i);
		}
	}
	for(int i=0;i<=s.top;i++){
		res[s.arr[i]]=-1;
	}
	for(int i=0;i<size;i++){
		cout<<res[i]<<" ";
	}
}
int main(){
	int arr[] = {1,0,2,4,3,6};
	int size = 6;
	Stack s;
	s.top = -1;
	Stack s1;
	s1.top = -1;
	PrintGreaterToRight(s,arr,size);
	cout<<endl;
	PrintSmallerToRight(s1,arr,size);
	
}