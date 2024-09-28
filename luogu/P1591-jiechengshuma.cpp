#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+5;
void mul(int a[],int x,int c[]){
    c[0]=a[0];
    int u=0;
    for (int i=1;i<=c[0];i++){
        int t=u+a[i]*x;
        c[i]=t%10;
        u=t/10;
    }
    while(u){
        c[++c[0]]=u%10;
        u/=10;
    }
}
int a[N];
int check(int x){
    int ans=0;
    for (int i=1;i<=a[0];i++) if (a[i]==x) ans++;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof a);
        a[0]=a[1]=1;
        int n,x;
        cin>>n>>x;
        for (int i=1;i<=n;i++){
            mul(a,i,a);
        }
        cout<<check(x)<<endl;
    }
    return 0;
}