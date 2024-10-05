#include <bits/stdc++.h>
using namespace std;
const int M=100+5;
const int N=1e4+5;
int cnt[M],w[N];//记cnt[i]表示第i个水龙头一共用了多少秒
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++){//当前等候队列的最前面是i号
        int minn=1;
        for (int j=1;j<=m;j++){
            if (cnt[j]<cnt[minn]) minn=j;
        }
        cnt[minn]+=w[i];
    }
    int ans=0;
    for (int i=1;i<=m;i++) ans=max(ans,cnt[i]);
    cout<<ans<<endl;
    return 0;
}