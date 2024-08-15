#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> s;
bool flag[105];
int main(){
	string a;
	cin>>a;
	for (int i=0;i<a.length();i++){
		if (a[i]=='(' || a[i]=='[') s.push(i);
		else if (a[i]==')'){
			if (s.empty() || a[s.top()]!='('){
				flag[i]=true;
			}
			else if (!s.empty()) s.pop();
		}
		else if (a[i]==']'){
			if (s.empty() || a[s.top()]!='['){
				flag[i]=true;
			}
			else if (!s.empty()) s.pop();
		}
		
	}
	while(!s.empty()){
		flag[s.top()]=true;
		s.pop();
	}
	for (int i=0;i<a.length();i++){
		if (flag[i]){
			if (a[i]=='(' || a[i]==')') cout<<"()";
			else if (a[i]=='[' || a[i]==']') cout<<"[]";
		}
		else cout<<a[i];
	}
	return 0;
}