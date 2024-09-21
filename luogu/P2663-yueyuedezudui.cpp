#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e2+5;
int a[N],f[N][N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        f[i][j]=f[i-1][j];
        
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}