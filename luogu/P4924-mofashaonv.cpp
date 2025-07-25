#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
int a[N][N];
int b[N][N];
int n,m;
void work(int x,int y,int r,int z){
    if (z){//逆时针：(x+i,y+j)-->(x-j,y+i)
        for (int i=-r;i<=r;i++){
            for (int j=-r;j<=r;j++){
                b[x-j][y+i]=a[x+i][y+j];
            }
        }
    }
    else{//顺时针：(x+i,y+j)-->(x+j,y-i)
        for (int i=-r;i<=r;i++){
            for (int j=-r;j<=r;j++){
                b[x+j][y-i]=a[x+i][y+j];
            }
        }
    }
}
int main(){
    cin>>n>>m;
    int c=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            a[i][j]=++c;
        }
    }
    int x,y,r,z;
    for (int i=1;i<=m;i++){
        cin>>x>>y>>r>>z;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                b[i][j]=a[i][j];
            }
        }
        work(x,y,r,z);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                a[i][j]=b[i][j];
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<a[i][j]<<" \n"[j==n];
        }
    }
    return 0;
}