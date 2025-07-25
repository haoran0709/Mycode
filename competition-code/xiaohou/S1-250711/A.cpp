#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int M=1e4+5;
int dis[N][N],a[M];
int main(){
	memset(dis,0x3f,sizeof dis);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>dis[i][j];
		}
	}
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int ans=0;
	for (int i=1;i<=m-1;i++){
		ans+=dis[a[i]][a[i+1]];
	}
	cout<<ans<<endl;
	return 0;
}
//92min