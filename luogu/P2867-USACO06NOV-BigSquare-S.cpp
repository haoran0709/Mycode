#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,ans;
char c[N][N];
bool check(int x,int y){
    if (x<1 || y<1 || x>n || y>n) return false;
    return true;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for (int x1=1;x1<=n;x1++){
        for (int y1=1;y1<=n;y1++){
            for (int x2=x1;x2<=n;x2++){
                for (int y2=y1;y2<=n;y2++){
                    int dis_x=x2-x1;
                    int dis_y=y2-y1;
                    int x3=x1-dis_y;
                    int y3=y1+dis_x;
                    int x4=x2-dis_y;
                    int y4=y2+dis_x;
                    if (check(x3,y3) && check(x4,y4)){
                        if (c[x1][y1]=='B' || c[x2][y2]=='B' || c[x3][y3]=='B' || c[x4][y4]=='B') continue;
                        int x=(c[x1][y1]=='J')+(c[x2][y2]=='J')+(c[x3][y3]=='J')+(c[x4][y4]=='J');
                        if (x<3) continue;
                        ans=max(ans,dis_x*dis_x+dis_y*dis_y);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}