#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> G[N];
int ans;
bool vis[N];
void DFS(int x,int fa){
	int res=0,now=1,cnt=0;
	for (int v:G[x]){
		if (v!=fa) res+=(!vis[v]);
	}
	while(now<res+1){
		now*=2;
		cnt++;
	}
	ans+=cnt+res;
	for (int v:G[x]){
		if (v!=fa){
			vis[v]=true;
			DFS(v,x);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vis[1]=true;
	DFS(1,0);
	cout<<ans<<endl;
	return 0;
}
//50min