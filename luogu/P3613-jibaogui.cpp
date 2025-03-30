#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
map<int,int> a[N];
int main(){
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=q;i++){
        int op;
        cin>>op;
        if (op==1){
            int x,y,k;
            cin>>x>>y>>k;
            a[x][y]=k;
        }
        else if (op==2){
            int x,y;
            cin>>x>>y;
            cout<<a[x][y]<<endl;
        }
    }
    return 0;
}