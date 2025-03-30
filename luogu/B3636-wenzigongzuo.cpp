#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int f[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        f[i]=f[i-1]+1;
        if (i%2==0) f[i]=f[i/2]+1;
    }
    cout<<f[n]-1<<endl;
    return 0;
}