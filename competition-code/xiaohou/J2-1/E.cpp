#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const int M=100+5;
const int K=50+5;
int a[N],f[N][M][K];//前i个苹果，还能移动j次，当前位置为k
int main(){
	int t,w,c;
	cin>>t>>w>>c;
	for (int i=1;i<=t;i++) cin>>a[i];
	if (a[1]!=1) f[1][w-1][a[1]]=1;
	else f[1][w][a[1]]=1;
	for (int i=2;i<=t;i++){
		for (int j=1;j<=w;j++){
			for (int k=1;k<=c;k++){
				f[i][j][k]=max(f[i][j][k],f[i-1][j][k]);
				if (a[i]==k) f[i][j][k]++;
				if (j<w) f[i][j][a[i]]=max(f[i][j][a[i]],f[i-1][j+1][k]+1);
			}
		}
	}
	for (int i=1;i<=t;i++){
		for (int j=1;j<=w;j++){
			for (int k=1;k<=c;k++){
				//printf("第%d分钟,还能移动了%d次,当前位置为%d,最多%d个苹果\n",i,j,k,f[i][j][k]);
			}
		}
	}
	cout<<f[t][w][c]<<endl;
	return 0;
}