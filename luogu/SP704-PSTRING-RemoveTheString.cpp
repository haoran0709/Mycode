#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    string x,y;
    while(cin>>x>>y){
        int ans=0;
        int a=x.find(y);
        while(a<x.length()){
            ans++;
            for (int i=a;i<=a+y.length();i++){
                char c=x[i];
                x[i]=' ';
                int b=x.find(y);
                if (b>a+y.length()){
                    break;
                }
                x[i]=c;
            }
            a=x.find(y);
        }
        cout<<ans<<endl;
    }
    return 0;
}