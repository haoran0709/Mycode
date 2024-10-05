#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=0x3f3f3f3f;
struct Node{
	int x,f;
};
vector <int> g[N];
queue <Node> q;
int n,m,Q,dis[N][2];
void BFS(){
	q.push({1,0});
	dis[1][0]=0;
	while(!q.empty()){
		Node now=q.front();
		q.pop();
		for (int v:g[now.x]){
			if (dis[v][(now.f+1)%2]==INF){
				q.push({v,now.f+1});
				dis[v][(now.f+1)%2]=now.f+1;
			}
		}
	}
}
int main(){
	memset(dis,INF,sizeof dis);
	cin>>n>>m>>Q;
	for (int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	BFS();
	for (int i=1;i<=Q;i++){
		int a,l;
		cin>>a>>l;
		if (dis[a][l%2]<=l) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}