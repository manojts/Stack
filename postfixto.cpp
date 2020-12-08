#include <bits/stdc++.h>
using namespace std;
class stak
{
public:
	int top;
	string arr[20];
	stak()
	{
		top=-1;
	}
	void push(string);
	string pop();
	void display();
};
void stak::push(string x)
{
	top++;
	arr[top]=x;
}
void stak::display()
{
	for(int i=0;i<=top;i++)
		cout<<arr[i]<<",";
	cout<<endl;
}

string stak::pop()
{
	string x;
	x=arr[top];
	top--;
	return x;

}
int isSymbol(char ch)
{
		switch(ch)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
		return 1;
		}
		return 0;

}
int main()
{
	string prefix;
	stak s;
	
	string s1,s2;
	string postfix;
	string infix;
	cin>>postfix;
	for(int i=0;i<postfix.length();i++)
	{
		if(isSymbol(postfix[i]))
		{
			s1=s2="";
			s1+=s.pop();
			s2+=s.pop();
			string temp="";
			temp=postfix[i]+s2+s1;
			s.push(temp);
		}
		else
		{
			string a="";
			a+=postfix[i];
			s.push(a);
		}
	}
	prefix=s.pop();
	//for(int i=prefix.length()-1;i>=0;i--)
		cout<<prefix;
	cout<<endl;
	for(int i=0;i<postfix.length();i++)
	{
		if(isSymbol(postfix[i]))
		{
			s1=s2="";
			s1+=s.pop();
			s2+=s.pop();
			string temp="";
			temp=')'+s1+postfix[i]+s2+'(';
			s.push(temp);
		}
		else
		{
			string a="";
			a+=postfix[i];
			s.push(a);
		}
	}
	infix=s.pop();
	for(int i=infix.length()-1;i>=0;i--)
		cout<<infix[i];
	cout<<endl;

	//cout<<reverse(infix) <<endl;
	return 0;
}
