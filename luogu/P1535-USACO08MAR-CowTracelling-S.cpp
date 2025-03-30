#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
struct Node{
    int x,y;
}s,e;
int n,m,t;
long long ans;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char a[N][N];
int vis[N][N][N];
int f(int x,int y,int st){
    int ans=0;
    if (vis[x][y][st]!=-1) return vis[x][y][st];
    if (st==0){
        if (x==e.x && y==e.y) return 1;
        return 0;
    }
    for (int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx<1 || ny<1 || nx>n || ny>m) continue;
        if (a[nx][ny]=='.'){
           ans+=f(nx,ny,st-1);
        }
    }
    return vis[x][y][st]=ans;
}
int main(){
    cin>>n>>m>>t;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    memset(vis,-1,sizeof vis);
    cin>>s.x>>s.y>>e.x>>e.y;
    cout<<f(s.x,s.y,t)<<endl;
    return 0;
}