#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],n;
bool cmp(int x,int y){
    return x>y;
}
int work(){
    int x=a[1];
    a[1]=ceil(x/2.0);
    int y=a[2];
    a[2]=ceil(y/2.0);
    int maxn=0,minn=1e9;
    for (int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
    }
    minn=min(maxn,minn);
    a[2]=y;
    a[1]=ceil(x/3.0);
    maxn=0;
    for (int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
    }
    minn=min(minn,maxn);
    return minn;
}
int main(){
    cin>>n;
    for (int i=1;i<=n-1;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    cout<<work()<<endl;
    return 0;
}