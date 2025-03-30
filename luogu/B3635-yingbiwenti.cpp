#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int f[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        f[i]=f[i-1]+1;
        if (i>=5) f[i]=min(f[i],f[i-5]+1);
        if (i>=11) f[i]=min(f[i],f[i-11]+1);
    }
    cout<<f[n]<<endl;
    return 0;
}