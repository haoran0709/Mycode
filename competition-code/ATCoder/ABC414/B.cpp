#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    for (int i=1;i<=n;i++){
        char c;
        long long x;
        cin>>c>>x;
        if (x>100){
            cout<<"Too Long\n";
            return 0;
        }
        for (int j=1;j<=x;j++) s+=c;
        if (s.length()>100){
            cout<<"Too Long\n";
            return 0;
        }
    }
    cout<<s<<endl;
    return 0;
}