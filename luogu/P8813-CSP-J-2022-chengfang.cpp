#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    long long ans=1;
    if (a==1){
        ans=1;
        cout<<ans<<endl;
        return 0;
    }
    if (a>1e9){
        cout<<-1<<endl;
        return 0;
    }
    for (int i=1;i<=b;i++){
        ans*=a;
        if (ans>1e9){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}