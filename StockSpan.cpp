#include <bits/stdc++.h>
using namespace std;
class Stack{
public:
	int top;
	int arr[50];
	void push(int data){
		top++;
		arr[top] = data;
	}
	int pop(){
		return arr[top--];
	}
};
void PrintGreaterToLeft(Stack s,int arr[],int size,int count){
	//cout<<1<<" ";
	for(int i=0;i<size;i++){
		count++;
		int ans=0;
		if(s.top==-1){
			s.push(arr[i]);
			ans=1;
		}
		else if(arr[i]<s.arr[s.top] ){
			//cout<<s.arr[s.top]<<" ";
			ans = i -s.top;
			s.push(arr[i]);
		}
		else {
			while(arr[i] > s.arr[s.top] && s.top>-1){
				count++;
				s.pop();
			}
			if(s.top==-1){
				//cout<<-1<<" ";
				ans=i;
			}
			else{
				//cout<<s.arr[s.top]<<" ";
				ans = i - s.top;
			}
			s.push(arr[i]);
		}
		cout<<ans<<" ";
	}
	cout<<endl<<count<<endl;
}
int main(){

	int arr[] = { 10, 4, 5, 6 ,90, 120, 80 ,100};
	//1 1 2 3 5 6 1 2
	int n = 8;
	Stack s;
	s.top=-1;
	PrintGreaterToLeft(s,arr,n,0);


}