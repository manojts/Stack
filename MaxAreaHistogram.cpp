#include<bits/stdc++.h> 
using namespace std; 

/*
	Find the near smaller to right indexes
	Find the near smaller to left indexes
	Find the width[i] = right[i] - left[i] - 1
	Find the area[i] = width[i] * arr[i];
	Find max in area
*/
class Stack
{
	public:
		int top;
		int arr[50];

		void push(int data)
		{
			arr[++top]=data;
		}

		int pop()
		{
			return arr[top--];
		}
};

void NSR(int arr[],int size,int res[]){
	Stack s,s1;
	s.top = -1;
	s1.top= -1;
	for(int i = size-1;i>=0;i--)
	{
		if(s.top==-1)
		{
			s.push(arr[i]);
			s1.push(i);
			res[i] = size ;
		}
		else
		{
			while(s.top>-1 && arr[i] <=s.arr[s.top])
			{
				s.pop();
				s1.pop();
			}
			if(s.top == -1)
			{
				res[i] = size ;
			}
			else
			{
				res[i] = s1.arr[s1.top];
			}
			s.push(arr[i]);
			s1.push(i);
		}
	}
}  
void NSL(int arr[],int size,int width[])
{
	Stack s,s1;
	s.top = -1;
	s1.top = -1;
	int res[size] = {0};
	for(int i = 0;i < size;i++)
	{
		if(s.top==-1){
			s.push(arr[i]);
			s1.push(i);
			res[i] = -1;
		}
		else
		{
			while(s.top>-1 && arr[i] <=s.arr[s.top])
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
				res[i] = s1.arr[s1.top] ;
			}
			s.push(arr[i]);
			s1.push(i);
		}
	}
	for(int i=0;i<size;i++)
	{
		width[i] = width[i] - res[i] -1;
		width[i] = width[i] * arr[i];
	}
}
int main(){
	int arr[] = { 11,11,10,10,10 };
	int n = 5;
	int width [n]={0};
	NSR(arr,n,width);
	NSL(arr,n,width);
	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(max < width[i])
			max = width[i];
		cout<<width[i]<<" ";
	}
	cout<<endl;
	cout<<"Maximum area is "<<max<<endl;
}