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

void PrintGreaterToLeft(Stack s,int arr[],int size){
int res[size] = {-1};
	for(int i = 0;i < size;i++)
	{
		if(s.top==-1){
			s.push(arr[i]);
			res[i] = -1;
		}
		else
		{
			while(s.top>-1 && arr[i] > s.arr[s.top])
			{
				s.pop();
			}
			if(s.top == -1)
			{
				res[i] = -1;
			}
			else
			{
				res[i] = s.arr[s.top];
			}
			s.push(arr[i]);
		}
	}
	for(int i = 0 ;i<size;i++){
		cout<<res[i]<<" ";
	}
}
void PrintSmallerToLeft(Stack s,int arr[],int size){
int res[size] = {-1};
	for(int i = 0;i < size;i++)
	{
		if(s.top==-1){
			s.push(arr[i]);
			res[i] = -1;
		}
		else
		{
			while(s.top>-1 && arr[i] < s.arr[s.top])
			{
				s.pop();
			}
			if(s.top == -1)
			{
				res[i] = -1;
			}
			else
			{
				res[i] = s.arr[s.top];
			}
			s.push(arr[i]);
		}
	}
	for(int i = 0 ;i<size;i++){
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
	PrintGreaterToLeft(s,arr,size);
	cout<<endl;
	PrintSmallerToLeft(s1,arr,size);
	
}