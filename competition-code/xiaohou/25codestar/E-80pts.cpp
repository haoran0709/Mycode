#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
int a[N];
int f[N][N];//记f[i][k]表示第i天打到第k个怪物
int n,m;
int work(int x,int y){//从x打到y
    int res=0;
    for (int i=x;i<=y;i++) res=max(res,a[i]);
    return res*(y-x+1);
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for (int i=1;i<=m;i++){
        for (int k=1;k<=n;k++){
            for (int j=1;j<=k;j++){
                f[i][k]=min(f[i][k],f[i-1][j-1]+work(j,k));//***
            }
        }
    }
    int ans=1e9;
    for (int i=1;i<=m;i++) ans=min(ans,f[i][n]);
    cout<<ans<<endl;
    return 0;
}