#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int maxn,minn=1e9;
int cnt[256];
bool isPrime(int x){
	if (x==1) return false;
	if (x==0) return false;
	for (int i=2;i*i<=x;i++){
		if (x%i==0) return false;
	}
	return true;
}
int main(){
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++){
		cnt[s[i]]++; 
	}
	for (int i='a';i<='z';i++){
		if (cnt[i]==0) continue;
		maxn=max(maxn,cnt[i]);
		minn=min(minn,cnt[i]);
	}
	if (isPrime(maxn-minn)) cout<<"Lucky Word"<<endl<<maxn-minn<<endl;
	else cout<<"No Answer"<<endl<<0<<endl;
	return 0;
}