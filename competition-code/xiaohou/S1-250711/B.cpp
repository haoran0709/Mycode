#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
	int x,w;
};
vector<Node> G[N];
long long dis[N];
void DFS(int x,int fa){
	for (Node v:G[x]){
		if (v.x!=fa){
			dis[v.x]=dis[x]+v.w;
			DFS(v.x,x);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	DFS(1,0);
	int a=1;
	for (int i=1;i<=n;i++){
		if (dis[i]>dis[a]) a=i;
	}
	memset(dis,0,sizeof dis);
	DFS(a,0);
	long long ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,dis[i]);
	cout<<ans<<endl;
	return 0;
}
//87min