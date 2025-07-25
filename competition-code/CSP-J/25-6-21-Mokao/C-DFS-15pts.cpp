#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N],a[N];
bool f[N];
int n,m,ans=1e9,res;
void DFS(int step,int cnt,int cost){
    if (step>n){
        if (cost>=m){
            if (cnt==4) cout<<cost<<endl;
            ans=min(ans,cnt);
        }
        return ;
    }
    f[step]=true;
    DFS(step+1,cnt+1,cost+p[step]);
    f[step]=false;
    DFS(step+1,cnt,cost);
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>p[i]>>a[i];
    }
    DFS(1,0,0);
    cout<<ans<<endl;
    cout<<0<<endl;
    return 0;
}