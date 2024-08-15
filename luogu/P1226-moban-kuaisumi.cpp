#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
long long qpow(LL a,LL b,LL p){
	LL c=1;
	while(b){
		if (b%2) c=c*a%p;
		a=a*a%p;
		b/=2;
	}
	return c;
}
int main(){
	LL a,b,p;
	cin>>a>>b>>p;
	printf("%lld^%lld mod %lld=%lld",a,b,p,qpow(a,b,p));
	return 0;
}