#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
char a[N][N];
int main(){
	string s;
	cin>>s;
	int n=s.length(),r=1,c;
	for (int i=1;i*i<=n;i++){
		if (n%i==0) r=i;
	}
	c=n/r;
	int now=0;
	for (int j=1;j<=c;j++){
		for (int i=1;i<=r;i++){
			a[i][j]=s[now++];
		}
	}
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++){
			cout<<a[i][j];
		}	
	}
	return 0;
}