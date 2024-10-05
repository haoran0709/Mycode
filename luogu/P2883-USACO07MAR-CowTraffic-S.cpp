#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5;
vector <int> g[N];
struct Road{
	int a,b;
}r[N];
int a[N],b[N];
bool vis[N];
int main(){
	int n,m;
	cin>>n>>m;
	a[0]=1;
	b[n]=1;
	for (int i=1;i<=m;i++){
		cin>>r[i].a>>r[i].b;
		g[r[i].a].push_back(r[i].b);
		vis[r[i].b]=true;
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]) g[0].push_back(i);
	}
	for (int u=0;u<=n;u++){
		for (int v:g[u]){
			a[v]+=a[u];
		}
	}
	for (int u=n;u>=0;u--){
		for (int v:g[u]){
			b[u]+=b[v];
		}
	}
	int ans=0;
	for (int i=1;i<=m;i++){
		ans=max(ans,a[r[i].a]*b[r[i].b]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
先建一个超级远点O（与所有入度为0的点连边）
对每个边u->v
	计算出：从0到u的路径数：a[u]
			从v到n的路径数：b[v]
		经过u->v的路线：a[u]*b[v]
如果能算出所有a,b，再遍历边就能得到答案了
*/