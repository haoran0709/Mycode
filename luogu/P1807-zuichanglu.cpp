#include <bits/stdc++.h>
using namespace std;
const int N=15e2+5;
struct Node{
	int u,x;
};
vector<Node> G[N];
priority_queue<Node> q;
bool operator <(Node A,Node B){
    return A.x < B.x;
}
int deg[N],f[N];
int n,m;
void topo(){
    for (int i=1;i<=n;i++){
        if (!deg[i]){
            q.push({i,0});
            f[i]=0;
        }
    }
    while(!q.empty()){
        Node now=q.top();
        q.pop();
        for (Node v:G[now.u]){
            deg[v.u]--;
            if (!deg[v.u]) q.push(v);
            f[v.u]=max(f[v.u],f[now.u]+v.x);
        }
    }
}
int main(){
    memset(f,-0x3f,sizeof f);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
        deg[v]++;
	}
	topo();
    if (f[n]<=-1e9) cout<<-1<<endl;
    else cout<<f[n]<<endl;
	return 0;
}  