#include <cstdio>
#include <iostream>
using namespace std;
const int N=40+5;
int n,ans;
int a[N];
void DFS(int step,int cnt1,int cnt0,int now){
    if (cnt1>n) return ;
    if (cnt0>n) return ;
    if (step > 2*n){
        ans++;
        /*
        for (int i=1;i<=2*n;i++){
            cout<<a[i]<<" \n"[i==2*n];
        }
        */
    }
    a[step]=1;  
    DFS(step+1,cnt1+1,cnt0,now+1);
    if (now>0){
        a[step]=0;
        DFS(step+1,cnt1,cnt0+1,now-1);
    }
}
int main(){
    cin>>n;
    DFS(1,0,0,0);
    cout<<ans<<endl;
    return 0;
}