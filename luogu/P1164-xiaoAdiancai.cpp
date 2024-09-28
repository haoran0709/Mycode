#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e2+5;
const int M=1e4+5;
int a[N],f[M];
int n,m;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        f[a[i]]++;
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (a[j]<=i && a[j]!=a[j-1]) f[i]+=f[i-a[j]];
            if (a[j]<=i && a[j]!=a[j-1] && i-a[j]==a[j]) f[i]--;
        }
    }
    for (int i=1;i<=m;i++) cout<<f[i]<<" ";
    cout<<f[m]<<endl;
    return 0;
}