#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int M=1e4+5;
int p[N][N];
int f[N][M];
int main(){
    int t,n,m;
    cin>>t>>n>>m;
    for (int i=1;i<=t;i++){
        for (int j=1;j<=n;j++){
            cin>>p[i][j];
        }
    }

    for (int i=1;i<=t;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=1e4;k++){
                f[j][k]=max(f[j][k],f[j][k-])
            }
        }
    }
    return 0;
}