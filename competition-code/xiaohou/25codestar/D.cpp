#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int f[N],g[N],h[N],a[N],b[N];
int n;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++){
        f[i]=1;
        if (h[i]>h[i-1]) f[i]=f[i-1]+1;
    }
    for (int i=n;i>=1;i--){
        g[i]=1;
        if (h[i]>h[i+1]) g[i]=g[i+1]+1;
    }
    int ans=0;
    for (int i=2;i<=n-1;i++){
        if (h[i-1]<h[i] && h[i]>h[i+1]) ans=max(ans,f[i]+g[i]-1);
        //cout<<i<<" "<<ans<<" "<<f[i]<<" "<<g[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}