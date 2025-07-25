#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long f[N][N];
struct Node{
    int v,w;
}a[N];
bool cmp(Node A,Node B){
    if (A.w!=B.w) return A.w > B.w;
    return A.v < B.v;
}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].v>>a[i].w;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=n;i>=1;i--){
        for (int j=1;j<=n;j++){
            f[i][j]=f[i+1][j];
            if (j-1+a[i].w > 0) f[i][j]=max(f[i][j],f[i+1][j-1+a[i].w]+a[i].v);
        }
    }
    /*
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<f[i][j]<<" \n"[j==n];
        }
    }
    */
    cout<<f[1][2]<<endl;
    return 0;
}