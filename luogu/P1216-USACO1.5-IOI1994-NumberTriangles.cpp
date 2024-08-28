#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e3+5;
int a[N][N],f[N][N],ans;
int main(){
    int r;
    cin>>r;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=r;i++){
        for (int j=1;j<=r;j++){
            f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
        }
    }
    for (int i=1;i<=r;i++){
        ans=max(ans,f[r][i]);
    }
    cout<<ans<<endl;
    return 0;
}