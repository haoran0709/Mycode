#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string a,b;
	cin>>a;
	b=a;
	int ans,m;
	ans=(a[0]-'0')*1+(a[2]-'0')*2+(a[3]-'0')*3+(a[4]-'0')*4+(a[6]-'0')*5+(a[7]-'0')*6+(a[8]-'0')*7+(a[9]-'0')*8+(a[10]-'0')*9;
	if (ans%11==10) b[12]='X';
	else b[12]=ans%11+'0';
	if (a==b) cout<<"Right"<<endl;
	else{
		cout<<b<<endl;
	}
	return 0;
}