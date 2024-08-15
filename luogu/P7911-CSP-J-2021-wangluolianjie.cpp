#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map <string,int> cnta;
long long d[1005];
int f;
bool check(string s){
	f=0;
	int c1=0,c2=0;
	long long x=0;
	s=s+':';
	bool fl=true;
	for (int i=0;i<s.length();i++){
		if (c1!=3 && c2!=0) return false;
		if (s[i]=='.'){
			if (i==0) return false;
			if (!isdigit(s[i+1])) return false;
			if (i==s.length()-1) return false;
			c1++;
			//cout << "x = " << x << endl;
			d[++f]=x;
			x=0;
		}
		else if (s[i]==':'){
			if (i==s.length()-2 && fl) return false;
			fl=false;
			c2++;
			d[++f]=x;
			x=0;
		}
		else{
			x=x*10+(s[i]-'0');
			if (x==0 && isdigit(s[i+1])) return false;
		}
	}
	if (f!=5) return false;
	for (int i=1;i<=4;i++){
		if (d[i]>255) return false;
	}
	if (d[5]>65535) return false;
	// for (int i=1;i<=5;i++) cout<<d[i]<<" ";
	// cout<<endl;
	if (c1!=3) return false;
	if (c2!=2) return false;
	return true;
}
string DO(string op,string ad,int x){
	if (!check(ad)){
		return "ERR";
	}
	else if (op=="Server"){//服务机
		if (cnta[ad]!=0) return "FAIL";
		cnta[ad]=x;
		return "OK";
	}
	else if (op=="Client"){//客户机
		if (cnta[ad]) return to_string(cnta[ad]);
		return "FAIL";
	}
}
int main(){
	int n;
	string op,ad;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>op>>ad;
		cout<<DO(op,ad,i)<<endl;
	}
	return 0;
}