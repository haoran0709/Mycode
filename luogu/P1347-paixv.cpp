#include <bits/stdc++.h>
using namespace std;
const int N=256+5;
vector<int> g[N],G[N];
queue<int> q;
bool vis[N][N],flag[N];
//记flag[i]表示i是否出现过
int f[N];
int degf[N],deg[N],n,m,now,xy;//记xy表示当前点数
char ans[N];
void copy(){
    memset(ans,0,sizeof ans);
    memset(f,0,sizeof f);
    for (int i=1;i<N;i++) deg[i]=degf[i];
    for (int i=1;i<N;i++){
        G[i].clear();
        for (int u:g[i]){
            G[i].push_back(u);
        }
    }
}
void topo(){
    int cnt=0;
    for (int i='A';i<='Z';i++){
        if (!deg[i] && flag[i]){
            q.push(i);
            f[i]=1;
        }
    }
    if (q.empty()){//TePan没有入度为0的点
        printf("Inconsistency found after %d relations.\n",now);
        exit(0);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cnt++;
        for (int v:G[u]){
            deg[v]--;
            if (!deg[v]){
                f[v]=max(f[v],f[u]+1);
                q.push(v);
            }
        }
    }

    //cout<<cnt<<endl;

    //判断并输出
    if (cnt!=xy){//判断自环*****
        printf("Inconsistency found after %d relations.\n",now);
        exit(0);
    }
    int c=0;//输出答案
    for (int i='A';i<='Z';i++) c=max(c,f[i]);
    if (c==n){
        for (char i='A';i<='Z';i++){
            if (ans[f[i]] && flag[i]){
                return ;
            }
            if (flag[i]){
                ans[f[i]]=i;
            }
        }
        printf("Sorted sequence determined after %d relations: ",now);
        for (int i=1;i<=n;i++) cout<<ans[i];
        cout<<".";
        exit(0);
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        now++;
        char a,b,c;
        cin>>a>>b>>c;
        xy+=!flag[a]+!flag[c];
        flag[a]=flag[c]=true;
        if (!vis[a][c]){//过滤重边
            g[a].push_back(c);
            degf[c]++;
            vis[a][c]=true;//***
        }
        copy();
        topo();
    }
    cout<<"Sorted sequence cannot be determined.\n";
    return 0;
}
/*
问题：

样例：
4 5
C<D
C<B
B<A
D<A
A<C

样例：
4 6
C<D
C<B
B<A
C<D
D<A
A<A
Inconsistency found after 6 relations.

样例：
10 30
D<J
E<F
H<F
J<B
J<E
F<B
C<A
B<I
H<F
B<G
E<A
H<A
F<J
C<H
J<E
F<I
J<F
I<F
G<A
J<B
H<F
D<C
G<I
F<C
D<E
A<E
J<E
E<H
A<D
A<J
Inconsistency found after 13 relations.
*/