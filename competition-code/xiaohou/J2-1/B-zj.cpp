#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
const int M=2e5+5;
int f[N][N],a[N][N];
int n,m,q;
void MAIN(){
	int x,y;
	cin>>x>>y;
	cout<<f[x][y]<<endl;
}
int main(){
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		a[l][r]++;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
		}
	}
	//for (int i=1;i<=n;i++) cout<<f[i]<<" \n"[i==n];
	for (int i=1;i<=q;i++) MAIN();
	return 0;
}