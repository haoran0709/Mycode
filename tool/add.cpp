#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+5;
int a[N],b[N],c[N];
void s2BIG(string s,int d[]){
	int dl=s.length();
	for (int i=0;i<dl;i++){
		d[dl-i]=s[i]-'0';
	}
	d[0]=dl;
}
void add(int a[],int b[],int c[]){
	int al=a[0],bl=b[0];
	int cl=max(al,bl);
	int u=0;
	for (int i=1;i<=cl;i++){
		int t=u;
		if (i<=al) t+=a[i];
		if (i<=bl) t+=b[i];
		c[i]=t%10;
		u=t/10;
	}
	if (u>0){
		cl++;
		c[cl]=u;
	}
	c[0]=cl;
}
void printBIG(int c[]){
	for (int i=c[0];i>=1;i--) cout<<c[i];
}
int main() {
	string s1,s2;
	cin>>s1>>s2;
	s2BIG(s1,a);
	s2BIG(s2,b);
	add(a,b,c);
	printBIG(c);
    return 0;
}