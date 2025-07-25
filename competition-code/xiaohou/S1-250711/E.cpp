#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Node{
	int x,t;
};
vector<Node> G[N];
int lea[N],cnt;//记录叶子节点
int ph[N];
int ans;
long long f1[N],f2[N],maxn;//f1为从上往下，f2为从下往上
void DFS(int x,int fa){
	if (G[x].size()==1){
		lea[++cnt]=x;
	}
	for (Node v:G[x]){
		if (v.x!=fa){
			ph[v.x]=x;
			f1[v.x]=f1[x]+v.t;
			DFS(v.x,x);
			f2[x]=max(f2[x],f2[v.x]+v.t);
		}
	}
}
void work(int x,int fa){
	if (f2[x]+f1[x]<maxn && f2[ph[x]]+f1[ph[x]]>=maxn){
		ans+=maxn-f2[x];
		f2[x]=maxn;
		//cout<<"here\n";
	}
	for (Node v:G[x]){
		if (v.x!=fa){
			work(v.x,x);
		}
	}
}
int main(){
	int n,s;
	cin>>n>>s;
	for (int i=1;i<=n-1;i++){
		int a,b,t;
		cin>>a>>b>>t;
		G[a].push_back({b,t});
		G[b].push_back({a,t});
	}
	DFS(s,0);
	//for (int i=1;i<=n;i++) cout<<f1[i]<<" \n"[i==n];
	//for (int i=1;i<=n;i++) cout<<f2[i]<<" \n"[i==n];
	for (int i=1;i<=cnt;i++){
		maxn=max(maxn,f1[lea[i]]);
	}
	work(s,0);
	cout<<ans<<endl;
	return 0;
}