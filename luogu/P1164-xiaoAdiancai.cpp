#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e2+5;
const int M=1e4+5;
int a[N];
int f[M];
int n,m;
int F(int x){
    if (f[x]) return f[x];
    if (x<0) return 0;
    if (x==0) return 1;
    for (int i=1;i<=n;i++){
        if (a[i]>x) break;
        f[x]+=F(x-a[i]);
    }
    return f[x];
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<F(m)<<endl;
    for (int i=1;i<=m;i++) cout<<f[i]<<" \n"[i==m];
    return 0;
}