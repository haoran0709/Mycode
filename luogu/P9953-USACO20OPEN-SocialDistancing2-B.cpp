#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3+5;
struct Cow{
    int x,f;
}a[N];
bool cmp(Cow A,Cow B){
    return A.x < B.x;
}
int main(){
    int n,ans=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].f;
    sort(a+1,a+n+1,cmp);
    int r=1e9;
    for (int i=1;i<=n;i++){//确定r
        if (i+1<=n && a[i].f==1 && a[i+1].f==0) r=min(r,a[i+1].x-a[i].x);
        if (i+1<=n && a[i].f==0 && a[i+1].f==1) r=min(r,a[i+1].x-a[i].x);
    }
    for (int i=1;i<=n;i++){
        if (a[i].f==1 && a[i-1].f==1 && a[i-1].x+r>a[i].x) continue;
        if (a[i].f==1) ans++; 
    }
    cout<<ans<<endl;
    return 0;
}