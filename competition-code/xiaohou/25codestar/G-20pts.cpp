#include <bits/stdc++.h>
using namespace std;
const int N=700+5;
int a[N][N],b[N][N],n,m,k;
int ans=1e9;
bool vis[N][N];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
void DFS(int x,int y,int cost,int t,int cnt){
    //cout<<x<<" "<<y<<" "<<cost<<" "<<t<<" "<<cnt<<endl;
    if (b[x][y] && cnt+1==k){
        ans=min(ans,cost);
        return ;
    }
    for (int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx<1 || ny<1 || nx>n || ny>m) continue;
        if (!vis[nx][ny] && !a[nx][ny]){
            vis[nx][ny]=true;
            if (b[x][y]){
                DFS(nx,ny,cost+t+b[x][y],t+b[x][y],cnt+1);
            }
            else DFS(nx,ny,cost+t,t,cnt);
            vis[nx][ny]=false;
        }
    }
}
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=k;i++){
        int x,y,w;
        cin>>x>>y>>w;
        b[x][y]=w;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            memset(vis,0,sizeof vis);
            if (b[i][j]){
                vis[i][j]=true;
                DFS(i,j,0,0,0);
                //cout<<i<<" "<<j<<" "<<ans<<endl;
                //cout<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}