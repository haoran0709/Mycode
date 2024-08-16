#include <cstdio>
#include <iostream>
using namespace std;
const int N=5e3+5;
const int M=6e3+5;
int f[N][M];
void s2BIG(string s,int a[]){
    a[0]=s.length();
    for (int i=0;i<a[0];i++){
        a[a[0]-i]=s[i]-'0';
    }
}
void add(int a[],int b[],int c[]){
    c[0]=max(a[0],b[0]);
    int u=0;
    for (int i=1;i<=c[0];i++){
        int t=u;
        if (i<=a[0]) t+=a[i];
        if (i<=b[0]) t+=b[i];
        u=t/10;
        c[i]=t%10;
    }
    if (u>0) c[++c[0]]=u;
}
void printBIG(int a[]){
    for (int i=a[0];i>=1;i--) cout<<a[i];
    cout<<endl;
}
int main(){
    int x;
    cin>>x;
    s2BIG("1",f[1]);
    s2BIG("2",f[2]);
    for (int i=3;i<=x;i++){
        add(f[i-1],f[i-2],f[i]);
    }
    //for (int i=1;i<=x;i++) printBIG(f[i]);
    printBIG(f[x]);
    return 0;
}