#include <cstdio>
#include <iostream>
using namespace std;
bool check(int n,int a,int b){
    if (n%b==1) return true;
    int x=1;
    while (x<=n){
        if ((n-x)%b==0) return true;
        x*=a;
    }
    return false;
}
void MAIN(){
    int n,a,b;
    cin>>n>>a>>b;
    if (check(n,a,b)) cout<<"Yes\n";
    else cout<<"No\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        MAIN();
    }
    return 0;
}