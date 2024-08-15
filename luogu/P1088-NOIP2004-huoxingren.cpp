#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[10005],b[10005],cnt;
bool f[10005];
void DFS(int step){
	if (step > n){
		cnt++;
		if (cnt==m+1){
			for (int i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];
			exit(0);
		}
		return ;
	}
	for (int i=1;i<=n;i++){
		if (cnt==0) i=a[step];
		if (!f[i]){
			b[step]=i;
			f[i]=1;
			DFS(step+1);
			f[i]=0;
		}
	}
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	DFS(1);
	return 0;
}
