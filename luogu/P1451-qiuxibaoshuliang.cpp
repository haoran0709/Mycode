//这道题刚开始对“细胞的定义为沿细胞数字上下左右若还是细胞数字则为同一细胞”的理解有些问题
//因此要认真读题，理解明白后就可以明白这是一道很简单的求连通块个数的题
#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e2+5;
int a[N][N],ans,n,m;
bool vis[N][N];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
void DFS(int x,int y){
    vis[x][y]=true;
    for (int i=0;i<4;i++){
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if (nx<1 || ny<1 || nx>n || ny>m) continue;
        if (a[nx][ny] && !vis[nx][ny]) DFS(nx,ny);
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin>>c;
            a[i][j]=c-'0';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j] && !vis[i][j]){
                DFS(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}