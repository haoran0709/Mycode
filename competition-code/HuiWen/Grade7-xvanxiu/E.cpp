#include <bits/stdc++.h>
using namespace std;
const int N=200+5;
int a[N],ans1,ans2,n,x;
int l[N],posl[N],posr[N];
int r[N];
bool f1[N],f2[N],v1[N],v2[N];
void DFSl(int now,int cnt){
	if (now<=1) return ;
	if (ans1==cnt){
		for (int i=x;i>=1;i--){
			if (f1[i]) cout<<i<<" ";
		}
		exit(0);
	}
	for (int i=now-2;i>=1;i--){
		f1[i]=true;
		DFSl(i,cnt+a[i]);
		f1[i]=false;
		DFSl(i,cnt);
	}
}
void DFSr(int now,int cnt){
	if (now>=n) return ;
	if (cnt==ans2){
		for (int i=x;i<=n;i++){
			if (f2[i]) cout<<i<<" "; 
		}
		exit(0);
	}
	for (int i=now+2;i<=n;i++){
		f2[i]=true;
		DFSr(i,cnt+a[i]);
		f2[i]=false;
		DFSr(i,cnt);
	}
}
int main(){
	cin>>n>>x;
	for (int i=1;i<=n;i++) cin>>a[i];
	r[x]=l[x]=a[x];
	for (int i=x-1;i>=1;i--){
		for (int j=i+2;j<=x;j++){
			l[i]=max(l[i],l[j]+a[i]);
		}
	}
	for (int i=x+1;i<=n;i++){
		for (int j=x;j<=i-2;j++){
			r[i]=max(r[i],r[j]+a[i]);
		}
	}
	int ans1=0,ans2=0;
	for (int i=1;i<=n;i++) ans1=max(ans1,l[i]);
	for (int i=1;i<=n;i++) ans2=max(ans2,r[i]);
	cout<<max(ans1,ans2)<<endl;
	if (ans1>ans2){
		DFSl(x,0);
	}
	else{
		DFSr(x,0);
		
	}
	return 0;
}
