#include <cstdio>
#include <iostream>
using namespace std;
using LL=long long;
const int N=60+5;
LL f[N];
int main(){
    int n;
    cin>>n;
    f[1]=1;
    f[2]=2;
    f[3]=4;
    for (int i=4;i<=n;i++){
        f[i]=f[i-1]+f[i-2]+f[i-3];
    }
    cout<<f[n]<<endl;
    return 0;
}