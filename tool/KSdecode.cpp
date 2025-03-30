#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
char next(int x){
    if (x<0) return 'A'+(x+26*500)%26;
    return 'A'+x%26;
}
int main(){
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++) a[i]=s[i]-'A';
    for (int k=1;k<=26;k++){
        for (int i=0;i<s.length();i++){
            cout<<next(a[i]+k);
        }
        cout<<endl;
    }
    for (int k=1;k<=26;k++){
        for (int i=0;i<s.length();i++){
            cout<<next(a[i]-k);
        }
        cout<<endl;
    }
    return 0;
}