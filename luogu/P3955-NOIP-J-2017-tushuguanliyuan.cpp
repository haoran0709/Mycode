#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
string a[N];
bool cmp(string A,string B){
    if (A.length() != B.length()) return A.length()<B.length();
    for (int i=0;i<A.length();i++){
        if (A[i]!=B[i]) return A[i] < B[i];
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    while (q--){
        bool flag=false;
        int x;
        cin>>x;
        string s;
        cin>>s;
        for (int i=1;i<=n;i++){
            if (a[i].length()<x) continue;
            if (a[i].substr(a[i].length()-x)==s){
                cout<<a[i]<<endl;
                flag=true;
                break;
            }
        }
        if (!flag) cout<<-1<<endl;
    }
    return 0;
}