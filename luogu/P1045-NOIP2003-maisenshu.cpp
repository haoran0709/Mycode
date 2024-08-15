#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include <cmath>
using namespace std;
const int N=500+5;
void Mul(int a[],int b,int c[]){
	c[0]=a[0];
	int u=0;
	for (int i=1;i<=c[0];i++){
		if (i>500) break;
		long long t=1ll*a[i]*b+u;
		c[i]=t%10;
		u=t/10;
	}
	while(u && c[0]<500){
		c[++c[0]]=u%10;
		u/=10;
	}
}
void printBIG(int a[]){
	int cnt=0;
	for (int i=500;i>=1;i--){
		cout<<a[i];
		cnt++;
		if (cnt==50){
			cnt=0;
			cout<<endl;
		}
	}
}
int a[N];
int main(){
	int p;
	cin>>p;
	cout<<int(p/log2(10))+1<<endl;
	a[0]=a[1]=1;
	for (int i=1;i<=p/20;i++){
		Mul(a,1048576,a);
	}
	for (int i=1;i<=p%20;i++){
		Mul(a,2,a);
	}
	a[1]--;
	printBIG(a);
	return 0;
}