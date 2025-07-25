#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t[N],cnt,now;
bool check(int x){
    if (t[x]==now) return true;
    return check(t[x]);
}
int main(){
    int n,ans=1e9;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<=n;i++){
        cnt=0;
        now=i;
        if (check(i)) ans=min(ans,cnt); 
    }
    cout<<ans<<endl;
    return 0;
}