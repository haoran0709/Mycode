#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100+5;
int a[N];
string check(int n,int k){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j) continue;
            if (abs(a[i]-a[j])==k) return "Yes\n";
        }
    }
    return "No\n";
}
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    cout<<check(n,k);
    return 0;
}