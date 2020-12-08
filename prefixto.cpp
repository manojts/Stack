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
	cin>>prefix;
	string s1,s2;
	string postfix;
	string infix;
	for(int i=prefix.length()-1;i>=0;i--)
	{
		if(isSymbol(prefix[i]))
		{
			s1=s2="";
			s1+=s.pop();
			s2+=s.pop();
			string temp="";
			temp=s1+s2+prefix[i];
			s.push(temp);
		}
		else
		{
			string a="";
			a+=prefix[i];
			s.push(a);
		}
	}
	postfix=s.pop();
	cout<<postfix<<endl;
	for(int i=prefix.length()-1;i>=0;i--)
	{
		if(isSymbol(prefix[i]))
		{
			s1=s2="";
			s1+=s.pop();
			s2+=s.pop();
			string temp="";
			temp='('+s1+prefix[i]+s2+')';
			s.push(temp);
		}
		else
		{
			string a="";
			a+=prefix[i];
			s.push(a);
		}
	}
	infix=s.pop();
	cout<<infix<<endl;
	return 0;
}
