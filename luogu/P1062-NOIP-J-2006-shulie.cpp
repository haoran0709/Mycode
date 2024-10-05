#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long f[N];
int main(){
    int k,n,x=0;
    cin>>k>>n;
    for (int i=1;i<=n;i++){
        int now=i;
        f[i]=pow(k,x);
        for (int j=1;j<now;j++){
            f[++i]=f[j]+f[now];
            if (i>n) break;
        }
        x++;
    }
    cout<<f[n]<<endl;
    return 0;
}