#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=20+5;
int h[N],dp[N],cou[N];
void MAIN(){
    int n,cnt=0,ans=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++){
        dp[i]=1;
        for (int j=1;j<=i-1;j++){
            if (h[j]<=h[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    for (int i=1;i<=n;i++){
        cou[i]=0;
        for (int j=1;j<=i-1;j++){
            if (h[j]<=h[i]){
                if (dp[i]==dp[j]+1) cou[i]+=max(cou[j],1);
            }
        }
    }
    // for (int i=1;i<=n;i++) cout<<dp[i]<<" \n"[i==n];
    // for (int i=1;i<=n;i++) cout<<cou[i]<<" \n"[i==n];
    for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
    for (int i=1;i<=n;i++){
        if (dp[i]==ans) cnt+=cou[i];
    }
    cout<<ans<<" "<<cnt<<endl;
}
int main(){
    int m;
    cin>>m;
    for (int i=1;i<=m;i++){
        MAIN();
    }
    return 0;
}