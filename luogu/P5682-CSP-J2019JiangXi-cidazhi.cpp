#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int maxn=0;
    for (int i=1;i<=n;i++) maxn=max(maxn,a[i]);
    int max1=-1,max2=-1;
    for (int i=1;i<=n;i++){
        int now=a[i]%maxn;
        if (now>max1){
            max2=max1;
            max1=now;
        }
        else if (now>max2 && now!=max1) max2=now;
    }
    cout<<max2<<endl;
    return 0;
}
/*
90pts

3
9 5 3

4
*/