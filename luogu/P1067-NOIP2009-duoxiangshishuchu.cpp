#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e2+5;
int a[N];
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n+1;i++){
		if (a[i]==0) continue;
		if (i!=1){
			if (a[i]<0) cout<<'-';
			else cout<<'+';
		}
		if (i==1 && a[i]<0) cout<<'-'; 
		if (a[i]!=1 && a[i]!=-1) cout<<abs(a[i]);
		if ((a[i]==1 || a[i]==-1) && i==n+1) cout<<abs(a[i]);
		if (n-i+1>1){
			cout<<"x^";
			cout<<n-i+1;
		}
		else if (n-i+1==1) cout<<"x";
	}
	return 0;
}
