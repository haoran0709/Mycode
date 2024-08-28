#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e5+5;
int a[N],f[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        f[i]=max(a[i],f[i-1]+a[i]);
    }
    int ans=-1e9;
    for (int i=1;i<=n;i++){
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}