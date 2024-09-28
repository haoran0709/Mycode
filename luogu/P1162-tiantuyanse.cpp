#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=30+5;
int a[N][N],n;
bool f[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void DFS(int x,int y){
	f[x][y]=true;
	for (int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx<0 || ny<0 || nx>n+1 || ny>n+1) continue;
		if (a[nx][ny]==0 && !f[nx][ny]) DFS(nx,ny);
	}
}
int main(){
    while(cin>>n){
    	int sx=0,sy=0;
    	for (int i=1;i<=n;i++){
    		for (int j=1;j<=n;j++){
    			cin>>a[i][j];
				f[i][j]=a[i][j];
			}
		}
		DFS(0,0);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (!f[i][j] && (!sx || !sy)){
					sx=i;
					sy=j;
				}
			}
		}
		//cout<<sx<<" "<<sy<<endl;
		memset(f,false,sizeof f);
		DFS(sx,sy);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (f[i][j]) a[i][j]=2;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				cout<<a[i][j]<<" \n"[j==n];
			}
		}
	}
    return 0;
}
//思路：为了找出填充2的连通块，可以使用DFS图上搜索，我们需要确定好出发点，对于出发点在图形本身的周围围上一圈0，这样从(0,0)开始做一次DFS就可以把不填2的0全部找到了，最后再填2即可