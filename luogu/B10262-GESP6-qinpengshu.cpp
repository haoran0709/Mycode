#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e6+5;
const int M=130+5;
int a[N];
long long f[2][M];
//long long 的效率要比int低一些，不必要的情况下不开long long
int main(){
    int p;
    long long ans=0;
    cin>>p;
    string s;
    cin>>s;
    int n=s.length();
    for (int i=1;i<=n;i++){
        a[i]=s[i-1]-'0';
        a[i]%=p;
        int x=i%2;
        for (int j=0;j<p;j++) f[x][j]=0;
        for (int j=0;j<p;j++){
            f[x][(j*10+a[i])%p]+=f[(x+1)%2][j];
        }
        f[x][a[i]]++;
        ans+=f[x][0];
    }
    cout<<ans<<endl;
    return 0;
}