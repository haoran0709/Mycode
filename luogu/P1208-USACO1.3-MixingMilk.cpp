#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct MI{
	int p,c;
}a[5005];
bool cmp(MI A,MI B){
	return A.p < B.p;
}
int main(){
	int n,m,ans=0;
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>a[i].p>>a[i].c;
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=m && n>0;i++){
		if (a[i].c > n){
			ans+=n*a[i].p;
			n=0;
		}
		else{
			n-=a[i].c;
			ans+=a[i].p*a[i].c;
		}
		if (n==0) break;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}