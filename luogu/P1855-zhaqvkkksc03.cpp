#include <bits/stdc++.h>
using namespace std;
const int N=100+5;
const int M=200+5;
int a[N],b[N],f[M][M];
int main(){
    int n,m,t;
    cin>>n>>m>>t;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=a[i];j--){
            for (int k=t;k>=b[i];k--){
                f[j][k]=max(f[j][k],f[j-a[i]][k-b[i]]+1);
            }
        }
    }
    cout<<f[m][t]<<endl;
    return 0;
}