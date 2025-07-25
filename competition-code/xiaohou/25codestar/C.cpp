#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    bool f=false;//是否反转
    int cnt=0;//有几张牌会被放到上面
    for (int i=1;i<=m;i++){
        int p;
        cin>>p;
        if (!p) f=!f;
        else{
            if (!f) cnt=(cnt+p)%n;
            else{
                cnt=(n+cnt-p)%n;
            }
        }
    }
    if (f){
        for (int i=1;i<=n;i++) b[n-i+1]=a[i];
        for (int i=1;i<=n;i++) a[i]=b[i];
        for (int i=cnt+1;i<=n;i++) cout<<a[i]<<" ";
        for (int i=1;i<=cnt;i++) cout<<a[i]<<" \n"[i==cnt];
    }
    else{
        for (int i=n-cnt+1;i<=n;i++) cout<<a[i]<<" ";
        for (int i=1;i<=n-cnt;i++) cout<<a[i]<<" \n"[i==n-cnt];
    }
    return 0;
}