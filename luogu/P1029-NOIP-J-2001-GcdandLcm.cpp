#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool f1[N],f2[N];
int a[N];
int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int x,y,ans=0;
    cin>>x>>y;
    for (int i=1;i*i<=y;i++){
        if (y%i==0){
            f1[y/i]=f1[i]=true;
        }
    }
    for (int i=1;i*x<N;i++) f2[i*x]=true;
    int cnt=0;
    for (int i=1;i<N;i++){
        if (f1[i] && f2[i]) a[++cnt]=i;
    }
    for (int i=1;i<=cnt;i++){
        for (int j=1;j<=cnt;j++){
            int res=gcd(a[i],a[j]);
            if (res==x && 1ll*a[i]/res*a[j]==y){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}