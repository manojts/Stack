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
//NGL index

void StockSpan(Stack s,int arr[],int size){
	Stack s1;
	s1.top = -1;
int res[size] = {-1};
	for(int i = 0;i < size;i++)
	{
		if(s.top==-1){
			s.push(arr[i]);
			s1.push(i);
			res[i] = -1;
		}
		else
		{
			while(s.top>-1 && arr[i] > s.arr[s.top])
			{
				s.pop();
				s1.pop();
			}
			if(s.top == -1)
			{
				res[i] = -1;
			}
			else
			{
				res[i] = s1.arr[s1.top];
			}
			s.push(arr[i]);
			s1.push(i);
		}
	}
	for(int i = 0 ;i<size;i++){
		cout<<i-res[i]<<" ";
	}
}
int main(){
	int arr[] = {100, 80, 60, 70, 60, 75, 85};
	int size = 7;
	Stack s;
	s.top = -1;
	Stack s1;
	s1.top = -1;
	StockSpan(s,arr,size);
	cout<<endl;
}
// 1, 1, 1, 2, 1, 4, 6