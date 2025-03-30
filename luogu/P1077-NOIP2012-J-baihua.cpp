#include <bits/stdc++.h>
using namespace std;
const int N=100+5;
const int mod=1e6+7;
int a[N],f[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++){
            for (int k=0;k<=a[i] && k<=j;k++){
                f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}