#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans1=0,ans2=0;
    while(n){
        if (n%3==1 && ans2==0) ans2=ans1+1;
        n-=ceil(1.0*n/3);
        ans1++;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}