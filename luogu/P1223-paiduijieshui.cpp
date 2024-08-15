#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct PD{
	int t,id;
}a[1005];
bool cmp(PD A,PD B){
	return A.t < B.t;
}
int main(){
	int n,cnt=0;
	double ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].t;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		cout<<a[i].id<<" ";
		ans+=cnt;
		cnt+=a[i].t;
	}
	cout<<"\n";
	printf("%.2lf",ans/n);
	return 0;
}