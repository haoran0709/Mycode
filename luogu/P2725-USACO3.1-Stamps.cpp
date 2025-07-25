#include <bits/stdc++.h>
using namespace std;
const int N=50+5;
const int M=2e6+5;
int a[N];
int f[M];//转换思路，记f[i]为凑出面值为i所需的邮票数
int main(){
    int k,n,ans=0;
    cin>>k>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for (int i=1;i<=2e6;i++){
        for (int j=1;j<=n;j++){
           if (i>=a[j]) f[i]=min(f[i],f[i-a[j]]+1);
        }
    }
    for (int i=1;i<=2e6;i++){
        if (f[i]>k){
            cout<<i-1<<endl;
            return 0;
        }
    }
    return 0;
}
/*
200 14
1 2 4 15 9 31 63 2100 3500 127 255 511 1000 1999

682938
*/