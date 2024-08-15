#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3+5;
int pos[N];
struct PT{
	int id,h,l,r;
}a[N];
bool cmp(PT A,PT B){
	if (A.h != B.h) return A.h > B.h;
	return A.id < B.id; 
}
bool check(int j,int x){
	if (x<a[j].r && x>a[j].l) return true;
	return false;
}
int main(){
	//freopen("PT.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].h>>a[i].l>>a[i].r;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		pos[a[i].id]=i;
	}
	for (int i=1;i<=n;i++){
		int x=pos[i];
		int l=a[x].l,r=a[x].r;
		bool f=false;
		int ans1=0,ans2=0;
		for (int j=x+1;j<=n;j++){
			if (a[j].h == a[x].h) continue;
			if (check(j,l)){
				f=true;
				ans1=a[j].id;
				break;
			}
		}
		f=false;
		for (int j=x+1;j<=n;j++){
			if (a[j].h == a[x].h) continue;
			if (check(j,r)){
				f=true;
				ans2=a[j].id;
				break;
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}