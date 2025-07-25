#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int x[N],y[N];
int main(){
    int n,l,r;
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    int ans=0;
    for (int i=1;i<=n;i++){
        if (x[i]<=l && y[i]>=r) ans++;
    }
    cout<<ans<<endl;
    return 0;
}