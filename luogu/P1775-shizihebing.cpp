#include <bits/stdc++.h>
const int N=3e2+5;
int a[N],f[N][N],sum[N];
using namespace std;
int main(){
	int n;
	cin>>n;
	memset(f,0x3f,sizeof f);
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		f[i][i]=0;
	}
	for (int l=2;l<=n;l++){
		for (int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			for (int k=i;k<j;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}