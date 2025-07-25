#include <bits/stdc++.h>
using namespace std;
const int N=350+5;
char a[N];
bool vis[N];
int n;
int next(int x){
    if (x%n==0) return n;
    return x%n;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for (int i=1;i<=n;i++){
        int j=next(i+1);
        vis[i]=vis[j]=true;
        int cnt=0;
        int now=next(i-1);
        while(!vis[now] && (a[now]==a[i] || a[now]=='w')){
            vis[now]=true;
            now=next(now-1);
        }
        now=next(j+1);
        while(!vis[now] && (a[now]==a[j] || a[now]=='w')){
            vis[now]=true;
            now=next(now+1);
        }
        for (int j=1;j<=n;j++){
            if (vis[j]){
                cnt++;
                vis[j]=false;
            }
        }
        ans=max(ans,cnt);
        //cout<<cnt<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
//rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr