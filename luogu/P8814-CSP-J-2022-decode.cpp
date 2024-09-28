#include <cstdio>
#include <iostream>
using namespace std;
void MAIN(){
    long long n,d,e;
    bool f=false;
    cin>>n>>d>>e;
    long long sum=n-(e*d-2);
    for (long long i=1;i*i<=n;i++){
        if (n%i==0 && i*sum-i*i==n){
            cout<<i<<" "<<n/i<<endl;
            f=true;
            break;
        }
    }
    if (!f) cout<<"NO\n";
}
int main(){
    int k;
    cin>>k;
    while(k--) MAIN();
    return 0;
}