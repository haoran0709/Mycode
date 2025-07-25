#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
int a[N];
int n,k,ans=1e9;
void DFS(int day,int cost,int cnt){
    //cout<<cnt<<endl;
    if (cnt==n) ans=min(ans,cost);
    if (day>k){
        if (cnt==n) ans=min(ans,cost);
        return ;
    }
    int maxn=0;
    for (int i=cnt+1;i<=n;i++){
        maxn=max(maxn,a[i]);
        DFS(day+1,cost+maxn*(i-cnt),i);
    }
}
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    DFS(1,0,0);
    cout<<ans<<endl;
    return 0;
}