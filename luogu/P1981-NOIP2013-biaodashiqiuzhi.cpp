#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
long long slove(){
    char c;
    while(cin>>c){
        
    }
}
int main(){
    long long x=slove();
    string s=to_string(x);
    if (s.length()<=4){
        cout<<s<<endl;
        return 0;
    }
    int ans=0;
    for (int i=s.length()-5;i<s.length();i++) ans=ans*10+(s[i]-'0');
    cout<<ans<<endl;
    return 0;
}