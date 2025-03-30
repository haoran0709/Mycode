#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
string a[N],b[N];
bool check(string s1,string s2){
    int now=0;
    for (int i=0;i<s1.length();i++){
        if (tolower(s1[i])==tolower(s2[now])) now++;
        if (now>=s2.length()) break;
    }
    if (now==s2.length()) return true;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=m;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        int ans=0;
        for (int j=1;j<=m;j++){
            ans+=check(a[i],b[j]);
        }
        cout<<ans<<endl;
    }
    return 0;
}