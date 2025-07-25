#include <bits/stdc++.h>
using namespace std;
const int N=250+5;
int a[N][N];
int ans[N];
int sum[N][N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin>>c;
            a[i][j]=c-'0';
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=2;k<=n;k++){
                int x=i+k-1,y=j+k-1;
                if (x>n || y>n) continue;
                if (sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1]==k*k) ans[k]++;
            }
        }
    }
    for (int i=2;i<=n;i++){
        if (ans[i]){
            cout<<i<<" "<<ans[i]<<endl;
        }
    }
    return 0;
}