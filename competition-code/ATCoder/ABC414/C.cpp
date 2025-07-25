#include <bits/stdc++.h>
using namespace std;
const int N=20+5;
int len,b[N],c[N],d[N],e[N];
long long ans,n;
bool check(int a[],int l){
    for (int i=1;i<=l/2;i++){
        int j=l-i+1;
        if (a[i]!=a[j]) return false;
    }
    return true;
}
void work(long long res){
    long long x=res;
    int c1=0,c2=0,cnt=0,c3;
    do{
        d[++cnt]=x%10;
        x/=10;
    }while(x);
    for (int i=1;i<=cnt;i++) e[i]=d[cnt-i+1];
    c3=cnt;
    for (int i=1+len%2;i<=cnt;i++){
        e[++c3]=d[i];
    }
    res=0;
    for (int i=1;i<=c3;i++) res=res*10+e[i];
    cout<<res<<endl;
    if (res>n) return ;
    x=res;
    do{
        b[++c1]=x%10;
        x/=10;
    }while(x);
    if (!check(b,c1)) return ;
    x=res;
    do{
        c[++c2]=x%8;
        x/=8;
    }while(x);
    if (!check(c,c2)) return ;
    //cout<<res<<endl;
    ans+=res;
}
void DFS(int step,long long now){
    work(now);
    if (step>ceil(1.0*len/2)){
        return ;
    }
    for (int i=0;i<=9;i++){
        DFS(step+1,now*10+i);
    }
}
int main(){
    int a;
    cin>>a>>n;
    long long x=n;
    do{
        x/=10;
        len++;
    }while(x);
    DFS(1,0);
    cout<<ans<<endl;
    return 0;
}