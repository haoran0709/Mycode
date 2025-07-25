#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N],a[N],f[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>p[i]>>a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            f[i][j]=f[i-1][j];
            f[i][j]=max(f[i][j],f[i-1][j-1]+p[i]);
        }
    }
    for (int i=1;i<=n;i++){
        if (f[n][i]>=m){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
/*
目标：50pts
*/