#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    string s,t;
    cin>>s;
    cin>>t;
    string s1=s,t1=t;
    for (int i=0;i<s.length();i++) s[i]=tolower(s[i]);
    for (int i=0;i<t.length();i++) t[i]=tolower(t[i]);
    int a=s.find("rioi");
    int b=t.find("rioi");
    if (a!=-1 && b!=-1) cout<<"Either is ok\n";
    else if (a!=-1) cout<<s1<<" for sure!\n";
    else if (b!=-1) cout<<t1<<" for sure!\n";
    else cout<<"Try again!\n"; 
    return 0;
}