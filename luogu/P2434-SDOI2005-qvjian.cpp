#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=50000;
struct QJ{
	int l,r;
}a[N];
bool cmp(QJ A,QJ B){
	return A.l < B.l;
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
	sort(a+1,a+n+1,cmp);
	int l=a[1].l,r=a[1].r;
	for (int i=1;i<=n;i++){
		if (a[i].l<=r){
			r=max(r,a[i].r);
			//printf("i=%d,l=%d,r=%d\n",i,l,r);
		}
		else{
			if (r==0) continue;
			cout<<l<<" "<<r<<"\n";
			l=a[i].l;
			r=a[i].r;
		}
	}
	cout<<l<<" "<<r<<"\n";
	return 0;
}

// 5
// 1 4
// 5 6
// 6 9
// 8 10
// 10 10