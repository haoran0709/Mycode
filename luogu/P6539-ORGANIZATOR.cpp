#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=2e6+5;
int a[N],cnt[M];
int main(){
	int n;
	long long ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for (int i=1;i<M;i++){
		int res=0;
		for (int j=1;j*i<M;j++){
			res+=cnt[i*j];
		}
		if (res>=2) ans=max(ans,1ll*res*i);
	}
	cout<<ans<<endl;
	return 0;
}
//开long long!!!