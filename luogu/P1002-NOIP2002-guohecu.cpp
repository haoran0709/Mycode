#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=20+5;
int hx[9]={0,1,-1,1,-1,2,-2,2,-2};
int hy[9]={0,-2,-2,2,2,-1,-1,1,1};
long long d[N][N];
bool vis[N][N];
struct Node{
    int x,y;
}h,e;
int main(){
    cin>>e.x>>e.y>>h.x>>h.y;
    d[0][1]=1;
    h.x++;
    h.y++;
    e.x++;
    e.y++;
    for (int i=0;i<9;i++){
        int nx=h.x+hx[i];
        int ny=h.y+hy[i];
        if (nx<1 || ny<1 || nx>e.x || ny>e.y) continue;
        vis[nx][ny]=true;
    }
    for (int i=1;i<=e.x;i++){
        for (int j=1;j<=e.y;j++){
            if (!vis[i][j]) d[i][j]=d[i-1][j]+d[i][j-1];
        }
    }
    cout<<d[e.x][e.y]<<endl;
    return 0;
}