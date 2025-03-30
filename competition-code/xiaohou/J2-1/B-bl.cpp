#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
const int M=2e5+5;
int f[N],d[N],l[M],r[M],g[N];
int n,m,q;
void MAIN1(){
	int x,y,cnt=0;
	cin>>x>>y;
	cout<<min(f[x],g[y])<<endl;
}
void MAIN2(){
	int x,y,cnt=0;
	cin>>x>>y;
	for (int i=1;i<=m;i++){
		if (x<=l[i] && r[i]<=y) cnt++;
	}
	cout<<cnt<<endl;
}
int main(){
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++){
		cin>>l[i]>>r[i];
	}
	//for (int i=1;i<=n;i++) cout<<f[i]<<" \n"[i==n];
	if (m*q<=100){
		for (int i=1;i<=q;i++) MAIN2();
	}
	else {
		for (int i=1;i<=m;i++){
			for (int j=1;j<=l[i];j++) f[j]++;
			for (int j=r[i];j<=n;j++) g[j]++;
		}
		for (int i=1;i<=q;i++) MAIN1();
	}
	return 0;
}