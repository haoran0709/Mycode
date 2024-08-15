#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
/*
递归版
LL qpow(LL a,LL b,LL mod){
	if (b==0) return 1;
	if (b==1) return a%mod;
	if (b%2==0){
		LL t=qpow(a,b/2,mod);
		return 1ll*t*t%mod;
	}
	if (b%2==1){
		LL t=qpow(a,b/2,mod);
		return 1ll*t*t%mod*a%mod;
	}
}
*/
//循环版（推荐）
LL qpow(LL a,LL b,LL p){
	LL res=1;
	while(b){
		if (b&1) res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res;
}
int main(){
	LL a,b,p;
	cin>>a>>b>>p;
	cout<<qpow(a,b,p);
	return 0;
}