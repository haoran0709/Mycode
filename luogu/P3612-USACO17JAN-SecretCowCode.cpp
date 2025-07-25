#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    long long n;
    cin>>s>>n;
    long long len=s.length();
    while(len<n){
        long long x=len;
        while(x<n) x*=2;
        x/=2;
        n-=(x+1);
        if (n==0) n=x;
    }
    cout<<s[n-1]<<endl;
    return 0;
}