#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> G[N];
int sum[N],a[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int m;
    cin>>m;
    for (int i=1;i<=m;i++){
        int p,x,y;
        cin>>p>>x>>y;
        if (p==1){
            
        }
        else if (p==2){

        }
    }
    int q;
    cin>>q;
    for (int i=1;i<=q;i++){

    }
    return 0;
}