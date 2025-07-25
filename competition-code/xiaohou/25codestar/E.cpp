#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
int a[N];
int f[N][N];//记f[i][k]表示第i天打到第k个怪物
int sum[N][N];
int n,m;
void init(){
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            int maxn=0;
            for (int k=i;k<=j;k++) maxn=max(maxn,a[k]);
            sum[i][j]=maxn*(j-i+1);
        }
    }
}
void print(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<sum[i][j]<<" \n"[j==n];
        }
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    init();
    //print();
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for (int i=1;i<=m;i++){
        for (int k=1;k<=n;k++){
            for (int j=1;j<=k;j++){
                f[i][k]=min(f[i][k],f[i-1][j-1]+sum[j][k]);//***
            }
        }
    }
    int ans=1e9;
    for (int i=1;i<=m;i++) ans=min(ans,f[i][n]);
    cout<<ans<<endl;
    return 0;
}