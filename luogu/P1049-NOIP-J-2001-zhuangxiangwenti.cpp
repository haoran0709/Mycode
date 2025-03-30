#include <bits/stdc++.h>
using namespace std;
const int N=30+5;
const int M=2e4+5;
int a[N],f[M];
int main(){
    int v,n;
    cin>>v>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=v;j>=a[i];j--){
            f[j]=max(f[j],f[j-a[i]]+a[i]);
        }
    }
    cout<<v-f[v]<<endl;
    return 0;
}