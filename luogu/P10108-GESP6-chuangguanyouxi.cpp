#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1e6+5;
const int M=1e2+5;
int a[M],b[N],f[N];
int n,m;
int main(){
    cin>>n>>m;
    memset(f,-0x3f3f3f,sizeof f);
    f[0]=0;
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n+n;i++){
        for (int j=1;j<=m;j++){
            if (i>=a[j]) f[i]=max(f[i],f[i-a[j]]+b[i-a[j]+1]);
        }
    }
    int ans=-1e9;
    for (int i=n;i<N;i++) ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}