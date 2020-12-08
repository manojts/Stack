#include <bits/stdc++.h>
using namespace std;
class Stack{
	public:
		int top;
		int stackArray[50];

		void push(int data){
			if(top==50){
				cout<<"Stack over flow"<<endl;
			}
			else
				stackArray[++top]=data;
		}

		int pop(){
			if(top==-1)
				cout<<"Stack underflow"<<endl;
			else
				return stackArray[top--];
		}

		void display(){
			for(int i=0;i<=top;i++){
				cout<<stackArray[i]<<" ";
			}
			cout<<endl;
		}

		int peek(){
			return stackArray[top];
		}

};

int main(){
	Stack obj;
	obj.top=-1;
	for(int i=0;i<10;i++){
		cout<<i<<" is pushed"<<endl;
		obj.push(i);
	}
	obj.display();
	cout<<"Poped "<<obj.pop()<<endl;
	obj.display();
}



