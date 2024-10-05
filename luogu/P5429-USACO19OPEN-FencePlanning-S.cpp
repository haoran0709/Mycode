#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	int x,y;
}a[N];
vector <int> g[N];
//记g[i]表示从i出发的所有边
//每个g[i]是一个vector
bool vis[N];
//记vis[i]表示点i是否访问过
int x_max,y_max,x_min=1e9,y_min=1e9,ans=1e9;
void DFS(int u){
	if (vis[u]) return ;
	vis[u]=true;
	x_max=max(x_max,a[u].x);
	y_max=max(y_max,a[u].y);
	x_min=min(x_min,a[u].x);
	y_min=min(y_min,a[u].y);
	for (int v:g[u]){//基于范围的循环
		DFS(v);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for (int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		//无向图，关系是相互的
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			x_max=0,y_max=0,x_min=1e9,y_min=1e9;
			DFS(i);
			ans=min(ans,2*(y_max+x_max-y_min-x_min));
		}
	}
	cout<<ans<<endl;
	return 0;
}