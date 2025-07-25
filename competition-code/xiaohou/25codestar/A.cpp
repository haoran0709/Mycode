#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
bool f[N][N];
void plant(int a,int b,int c,int d){
    for (int i=a+1;i<=c;i++){
        for (int j=b+1;j<=d;j++){
            f[i][j]=true;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        plant(a,b,c,d);
    }
    int ans=0;
    for (int i=1;i<=1000;i++){
        for (int j=1;j<=1000;j++){
            ans+=f[i][j];
            //if (f[i][j]) cout<<i<<" "<<j<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}