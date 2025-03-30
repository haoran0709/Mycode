/*
ID: yanghr71
TASK: ride
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    string s1,s2;
    cin>>s1>>s2;
    long long a=1,b=1;
    for (int i=0;i<s1.length();i++) a*=(s1[i]-'A')+1;
    for (int i=0;i<s2.length();i++) b*=(s2[i]-'A')+1;
    if (a%47==b%47) cout<<"GO\n";
    else cout<<"STAY\n";
    return 0;
}