#include <bits/stdc++.h>
using namespace std;
const int N=2e2+5;
int cnt[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        cnt[s[0]]++;
    }
    long long ans=1;
    if (cnt['J']) ans*=cnt['J'];
    if (cnt['N']) ans*=cnt['N'];
    if (cnt['E']) ans*=cnt['E'];
    cout<<ans<<endl;
    return 0;
}