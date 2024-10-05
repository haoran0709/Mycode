#include <bits/stdc++.h>
using namespace std;
int count2(int x){
    int res=0;
    do{
        if (x%10==2) res++;
        x/=10;
    }while(x);
    return res;
}
int main(){
    int l,r,ans=0;
    cin>>l>>r;
    for (int i=l;i<=r;i++){
        ans+=count2(i);
    }
    cout<<ans<<endl;
    return 0;
}