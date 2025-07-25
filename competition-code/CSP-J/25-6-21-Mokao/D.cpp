#include <bits/stdc++.h>
using namespace std;
const int N=800+5;
char c[N][N];
void MAIN(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }

}
int main(){
    int t;
    cin>>t;
    while(t--) MAIN();
    return 0;
}