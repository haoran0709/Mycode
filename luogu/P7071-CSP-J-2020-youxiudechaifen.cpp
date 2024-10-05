#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if (n%2!=0) cout<<-1<<endl;
    else{
        while(n){
            cout<<int(pow(2,int(log2(n))))<<" ";
            n-=pow(2,int(log2(n)));
        }
    }
    return 0;
}