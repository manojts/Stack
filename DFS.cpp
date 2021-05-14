#include<bits/stdc++.h>
using namespace std;
void DFS(int source,int matrix[10][10],int visited[10],int n){
	stack<int>s;
	s.push(source);
	visited[source] = 1;
	while(!s.empty()){
		source = s.top();
		s.pop();
		cout<<source<<endl;
		for(int i=0;i<n;i++){
			if(visited[i]!=1 && matrix[source][i]){
				s.push(i);
				visited[i] = 1;
			}
		}
	}
}
int main(){
	int source;
	cin>>source;
	int matrix[10][10];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}
	int visited[10]={0};
	DFS(source,matrix,visited,n);
}
