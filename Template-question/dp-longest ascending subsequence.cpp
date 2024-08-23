#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e3+5;
int a[N],dp[N],ans;
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		dp[i]=1;
		for (int j=1;j<=i-1;j++){
			if (a[j]<a[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	for (int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}


/*伪代码
时间复杂度:o(n^2)
f[i]:以a[i]为结尾，最长上升子序列长度
for i:1 -> n
    f[i]=1;
    for j:1 -> i-1
        if a[j] < a[i]
            f[i] <- f[j]+1 //状态转移方程
ans=max{f[1]~f[n]}
*/