#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1e5+5;
int a[N],v[N];
int main(){
    int n,d;
    long long ans=0;
    cin>>n>>d;
    for (int i=1;i<=n-1;i++) cin>>v[i];
    for (int i=1;i<=n;i++) cin>>a[i];
    long long now=1e9,cnt=0;
    for (int i=1;i<=n-1;i++){
        if (now>a[i]){
            ans+=now*ceil(1.0*cnt/d);
            cnt=0-d*ceil(1.0*cnt/d)+cnt;
            now=a[i];
        }
        cnt+=v[i];
    }
    ans+=now*ceil(1.0*cnt/d);
    cout<<ans<<endl;
    return 0;
}