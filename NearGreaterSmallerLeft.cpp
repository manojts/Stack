#include <bits/stdc++.h>
using namespace std;
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

void PrintSmallerToRight(Stack s,int arr[],int size){
	int res[size] = {0};
	for(int i=size-1;i>0;i--)
	{
		if(s.top==-1)
		{
			s.push(size-1-i);
		}
		else if(arr[i]<=s.arr[s.top])
		{
			s.push(size-1-i);
		}
		else
		{
			while( arr[i] > s.arr[s.top] && s.top >-1 ){
			res[s.pop()] = arr[i];
			//s.pop();
		}
			s.push(size-1-i);
		}
	}
	for(int i=0;i<=s.top;i++){
		res[s.arr[i]]=-1;
	}
	for(int i=0;i<size;i++){
		cout<<res[i]<<" ";
	}
}
void PrintSmallerToLeft(Stack s,int arr[],int size){
	for(int i=0;i<size;i++){
		if(s.top==-1){
			s.push(arr[i]);
			cout<<-1<<" ";
		}
		else if(arr[i]>s.arr[s.top] ){
			cout<<s.arr[s.top]<<" ";
			s.push(arr[i]);
		}
		else {
			while(arr[i] < s.arr[s.top] && s.top>-1){
				s.pop();
			}
			if(s.top==-1){
				cout<<-1<<" ";
			}
			else{
				cout<<s.arr[s.top]<<" ";
			}
			s.push(arr[i]);
		}
	}
}
int main(){
	int arr[] = {1,0,2,4,3,6};
	int size = 6;
	Stack s;
	s.top = -1;
	Stack s1;
	s1.top = -1;
	PrintSmallerToRight(s,arr,size);
	cout<<endl;
	//PrintSmallerToLeft(s1,arr,size);
	
}