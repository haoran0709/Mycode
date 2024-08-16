#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e3+5;
int f[N];
int F(int x){
    if (f[x]) return f[x];
    f[x]=1;
    for (int i=1;i<=x/2;i++){
        f[x]+=F(i);
    }
    return f[x];
}
int main(){
    int n;
    cin>>n;
    cout<<F(n)<<endl;
    //for (int i=1;i<=n;i++) cout<<f[i]<<" \n"[i==n];
    return 0;
}