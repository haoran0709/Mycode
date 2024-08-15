#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=505;
struct Game{
	int t,w;
}a[N];
bool cmp(Game A,Game B){
	return A.w > B.w;
}
bool f[N];
int main(){
	int m,n;
	cin>>m>>n;
	for (int i=1;i<=n;i++) cin>>a[i].t;
	for (int i=1;i<=n;i++) cin>>a[i].w;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		bool flag=false;
		for (int j=a[i].t;j>=1;j--){
			if (!f[j]){
				flag=true;
				f[j]=true;
				break;
			}
		}
		if (!flag) m-=a[i].w;
	}
	cout<<m<<endl;
	return 0;
}
