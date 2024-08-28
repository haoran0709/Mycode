#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=250+5;
int a[N][N],cnt[N*N];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
bool vis[N][N];
int n,m,ans,res;
void DFS(int x,int y){
    res++;
    vis[x][y]=true;
    for (int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (a[nx][ny] && !vis[nx][ny]) DFS(nx,ny);
    }
}
void init(){
    memset(vis,false,sizeof vis);
    ans=0;
    memset(cnt,0,sizeof cnt);
}
void Print(){
    cout<<ans<<endl;
    for (int i=1;i<N*N;i++){
        if (cnt[i]) cout<<i<<" "<<cnt[i]<<endl;
    }
}
void MAIN(){
    init();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j] && !vis[i][j]){
                res=0;
                DFS(i,j);
                cnt[res]++;
                ans++;
            }
        }
    }
    Print();
}
int main(){
    while(true){
        cin>>n>>m;
        if (n==0 && m==0) break;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        MAIN();
    }
    return 0;
}