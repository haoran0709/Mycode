#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int f[N][N],l[N],w[N],u[N];
int main(){
	int n,x;
	cin>>n>>x;
	for (int i=1;i<=n;i++){
		cin>>l[i]>>w[i]>>u[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<=x;j++){
			if (j>=u[i]){
				f[i][j]=max(f[i-1][j]+l[i],f[i-1][j-u[i]]+w[i]);
			}
			else f[i][j]=f[i-1][j]+l[i];
		}
	}
	cout<<f[n][x]*5ll<<endl;
	return 0;
}