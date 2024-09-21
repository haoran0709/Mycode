#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=2e3+5;
int a[N][N],cnt[N*N];
bool f[N][N];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int n,k,ans=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            ans+=a[i][j];
        }
    }
    for (int i=1;i<=k;i++){
        int res=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<n;j++){
                if (!f[i][j] && !f[i][j+1]) cnt[++res]=a[i][j]+a[i][j+1];
            }
        }
        for (int j=1;j<=n;j++){
            for (int i=1;i<n;i++){
                if (!f[i][j] && !f[i+1][j]) cnt[++res]=a[i][j]+a[i+1][j];
            }
        }
        sort(cnt+1,cnt+res+1,cmp);
        ans-=cnt[1];
        for (int i=1;i<=n;i++){
            for (int j=1;j<n;j++){
                if (!f[i][j] && !f[i][j+1]){
                    if (cnt[1]==a[i][j]+a[i][j+1]){
                        f[i][j]=true;
                        f[i][j+1]=true;
                        continue;
                    }
                }
            }
        }
        for (int j=1;j<=n;j++){
            for (int i=1;i<n;i++){
                if (!f[i][j] && !f[i+1][j]){
                    if (cnt[1]==a[i][j]+a[i+1][j]){
                        f[i][j]=true;
                        f[i+1][j]=true;
                        continue;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}