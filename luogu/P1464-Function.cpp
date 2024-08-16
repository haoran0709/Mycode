#include <cstdio>
#include <iostream>
using LL=long long;
using namespace std;
const int N=25;
LL f[N][N][N];
LL F(LL a,LL b,LL c){
    if (a<=0 || b<=0 || c<=0) return 1;
    if (a>20 || b>20 || c>20) return F(20,20,20);//*
    if (f[a][b][c]) return f[a][b][c];
    if (a<b && b<c) return f[a][b][c]=F(a,b,c-1)+F(a,b-1,c-1)-F(a,b-1,c);
    return f[a][b][c]=F(a-1,b,c)+F(a-1,b-1,c)+F(a-1,b,c-1)-F(a-1,b-1,c-1);
}
int main(){
    LL a,b,c;
    while(cin>>a>>b>>c){
        if (a==-1 && b==-1 && c==-1) break;
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,F(a,b,c));
    }
    return 0;
}