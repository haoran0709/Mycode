#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=35e2+5;
const int M=12880+5;
int w[N],d[N],dp[M];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>w[i]>>d[i];
    for (int i=1;i<=n;i++){
        for (int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}