#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int h[N];
int n,m;
bool check(int x){
    long long res=0;
    for (int i=1;i<=n;i++) res+=max(h[i]-x,0);
    return res>=m;
}
int main(){
    cin>>n>>m;
    int l=1,r=0;
    for (int i=1;i<=n;i++){
        cin>>h[i];
        r=max(r,h[i]);
    }
    while(l<r){
        int mid=(l+r+1)/2;
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}