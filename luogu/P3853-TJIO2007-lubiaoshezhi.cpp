#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
bool f[N];
int len,n,k;
bool check(int x){
    int res=0;
    int cnt=0;
    for (int i=1;i<=len;i++){
        res++;
        if (f[i]) res=0;
        if (res==x) cnt++,res=0;
        if (cnt>k) return false;
    }
    return cnt<=k;
}
int main(){
    cin>>len>>n>>k;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        f[x]=true;
    }
    int l=1,r=1e7;
    while(l<r){
        int mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}