#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
int f[N];
bool check(string s){
	for (int i=1;i<s.length();i++){
		if (s[i]=='m') return true;
		if (s[i]=='w') return true;
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=' '+s;
	if (check(s)){
		cout<<0<<endl;
		return 0;
	}
	f[0]=1;
	for (int i=1;i<=n;i++){
		f[i]=f[i-1];
		if (s[i]=='n' && s[i-1]=='n') f[i]=(f[i-1]+f[i-2])%mod;
		if (s[i]=='v' && s[i-1]=='v') f[i]=(f[i-1]+f[i-2])%mod;
	}
	cout<<f[n]<<endl;
	return 0;
}