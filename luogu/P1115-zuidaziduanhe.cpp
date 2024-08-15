#include <cstdio>
#include <iostream>
using namespace std;
const int N=2e5+5; 
int a[N],dp[N];
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		dp[i]=a[i];
		dp[i]=max(dp[i],dp[i-1]+a[i]);
	}
	int ans=-1e9;//***
	for (int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
		//cout<<dp[i]<<" \n"[i==n];
	}
	cout<<ans<<endl; 
	return 0;
} 