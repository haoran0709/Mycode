#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3+5;
struct Node{
    int x,t;
}a[N];
bool cmp(Node A,Node B){
    return A.t < B.t;
}
void MAIN(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].t;
    sort(a+1,a+n+1,cmp);
    int now=0,tim=0;
    for (int i=1;i<=n;i++){
        if (abs(now-a[i].x)>(a[i].t-tim)){
            cout<<"Notabletocatch\n";
            return ;
        }
        tim=a[i].t;
        now=a[i].x;
    }
    cout<<"Abletocatch\n";
}
int main(){
    int g;
    cin>>g;
    while(g--) MAIN();
    return 0;
}