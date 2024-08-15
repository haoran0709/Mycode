#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N=1e6+5;
void s2BIG(string s,int a[]){
	int al=s.length();
	for (int i=0;i<s.length();i++){
		a[al-i]=s[i]-'0';
	}
	a[0]=al;
}
bool cmpBIG(int a[],int b[]){
	int al=a[0],bl=b[0];
	if (al!=bl) return al>bl;
	for (int i=al;i>=1;i--){
		if (a[i]!=b[i]){
			return a[i]>b[i];
		}
	}
	return false;
}
void sub(int a[],int b[],int c[]){
	int al=a[0],bl=b[0];
	int cl=max(al,bl);
	int u=0;
	for (int i=1;i<=cl;i++){
		int t=a[i]-u;
		if (i<=bl) t-=b[i];
		if (t<0){
			c[i]=t+10;
			u=1;
		}
		else{
			c[i]=t;
			u=0;
		}
	}
	while(c[cl]==0 && cl>1) cl--;
	c[0]=cl;
}
void printBIG(int a[]){
	for (int i=a[0];i>=1;i--) cout<<a[i];
}
int a[N],b[N],c[N];
int main() {
	string s1,s2;
	cin>>s1>>s2;
	s2BIG(s1,a);
	s2BIG(s2,b);
	if (cmpBIG(a,b)){
		sub(a,b,c);
	}
	else sub(b,a,c);
	printBIG(c);
    return 0;
}