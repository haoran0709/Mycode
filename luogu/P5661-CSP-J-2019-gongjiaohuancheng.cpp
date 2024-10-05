#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int op[N],p[N],t[N];
bool vis[N];//记录优惠劵是否可用
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>op[i]>>p[i]>>t[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (op[i]==0){
			ans+=p[i];
		}
		else{
			int x=-1;
			for (int j=i-1;j>=1;j--){
				if (t[i]-t[j]>45) break;
				if (vis[j] || op[j] || p[j]<p[i]) continue;
				x=j;
			}
			if (x==-1) ans+=p[i];
			else vis[x]=true;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
1.优惠票有效期45分钟->最多45分钟票可用
2.用最早的
3.优惠价格>=公交价格
*/