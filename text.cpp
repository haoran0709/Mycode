#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int t(int x){
    cnt++;
    if (x==0) return 1;
    return t(x-1)+x;
}
int main(){
    int n;
    cin>>n;
    cout<<t(n)<<endl;
    cout<<cnt<<endl;
    return 0;
}