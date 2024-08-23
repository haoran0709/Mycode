#include <bits/stdc++.h>
using namespace std;
const int N=200+5;
bool f[N];
int n,m,cnt,ans,res;
int jump(int x,int c){
    int cou=0;
    while (cou<=c && x<=n){
        x++;
        if (!f[x]) cou++;
    }
    if (x>n){
        x=jump(0,c);
    }
    return x;
}
int main(){
    cin>>n>>m;
    int x=0;
    while (true){
        cnt++;
        x=jump(x,cnt*cnt*cnt%5+1);
        f[x]=true;
        ans=x;
        res++;
        if (res==m){
            cout<<ans<<endl;
            break;
        }
        //cout<<ans<<endl;
    }
    return 0;
}