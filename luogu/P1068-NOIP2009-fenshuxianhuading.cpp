#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int fs;
struct Person{
	int k,s;
};
bool cmp(Person A,Person B){
	if (A.s != B.s) return A.s > B.s;
	return A.k <= B.k;
}
int main(){
	int cnt=0;
	Person a[5005];
	int n,m;
	scanf("%d%d",&n,&m);
	fs=m*3/2;
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].k,&a[i].s);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) if (a[i].s>=a[fs].s) cnt++;
	printf("%d %d\n",a[fs].s,cnt);
	for (int i=1;i<=cnt;i++) printf("%d %d\n",a[i].k,a[i].s);
	return 0;
}