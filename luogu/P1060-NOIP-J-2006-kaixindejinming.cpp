#include <bits/stdc++.h>
using namespace std;
const int N=3e4+5;
struct Node{
    int v,p;
}a[N];
bool cmp(Node A,Node B){
    if (A.p != B.p) return A.p > B.p;
    return A.v > B.v;
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i].v>>a[i].p;
    sort(a+1,a+n+1,cmp);
    int res=0,ans=0;
    for (int i=1;i<=m;i++){
        if (res+a[i].v<=n){
            res+=a[i].v;
            ans+=a[i].v*a[i].p;
        }
    }
    cout<<ans<<endl;
    return 0;
}