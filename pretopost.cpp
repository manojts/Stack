#include <iostream>
#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;
class stack1
{
public:
	int top;
	string arr[20];
	stack1()
	{
		top=-1;
	}
	void push(string s)
	{
		top++;
		arr[top]=s;
	}
	string pop()
	{
		string x=arr[top];
		top--;
		return x;
	}
};
int isoperator(char c)
{
	switch (c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		return 1;
	}
	return 0;
}
int main()
{
	stack1 stk;
	int len;
	string prefix;
	cin>>prefix;
	len=prefix.length();
	for(int i=len-1;i>=0;i--)
	{
		if(isoperator(prefix[i]))
		{
			string s1=stk.pop();
			string s2=stk.pop();
			string temp=s1+s2+prefix[i];
			//cout<<temp<<endl;
			stk.push(temp);
			s1=s2=temp="";

		}
		else
		{
			string a=a+prefix[i];
			stk.push(a);
			cout<<a<<endl;
			a="";
		}
	}
	cout<<stk.arr[0]<<endl;
}