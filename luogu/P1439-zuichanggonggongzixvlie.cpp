#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],f[N],c[N],pos[N],t[N];
int main(){
	memset(f,0x3f,sizeof f);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		cin>>b[i];
		pos[b[i]]=i;
	}
	for (int i=1;i<=n;i++) t[i]=pos[a[i]];
	//for (int i=1;i<=n;i++) cout<<t[i]<<" \n"[i==n];
	for (int i=1;i<=n;i++){
		int k=lower_bound(f+1,f+n+1,t[i])-f;
		f[k]=t[i];//*
		c[i]=k;
	}
	//for (int i=1;i<=n;i++) cout<<pos[a[i]]<<" \n"[i==n];
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,c[i]);
	cout<<ans<<endl;
	return 0;
}