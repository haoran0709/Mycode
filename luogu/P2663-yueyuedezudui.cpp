#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e2+5;
int a[N],f[N];
int main(){
    int n,sum=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=1;i<=n;i++){
        f[i]=a[i];
        for (int j=1;j<i;j++){
            if ((a[i]+f[j])*2 > sum) continue;
            f[i]=max(f[i],f[j]+a[i]);
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}