#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++){
        int x;
        cin>>x;
        cout<<a[x]<<endl;
    }
    return 0;
}