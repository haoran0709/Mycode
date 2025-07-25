#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> G[N];
bool vis[N];
int n,d,cnt;
void DFS(int u,int step){
    vis[u]=true;
    cnt++;
    if (step>=d) return ;
    for (int v:G[u]){
        if (!vis[v]) DFS(v,step+1);
    }
}
int main(){
    cin>>n>>d;
    for (int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1,0);
    cout<<cnt-1<<endl;
    return 0;
}