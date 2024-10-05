#include <bits/stdc++.h>
using namespace std;
const int N=50+5;
struct Point{
	int x,y;
};
vector<Point> a[4];//存3个斑点内的所有点
char c[N][N];
int n,m,d1,d2,d3,cnt,ans;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[N][N];
int getmin(int x,int y,int k){
	int res=1e9;
	for (Point i:a[k]){
		res=min(res,abs(i.x-x)+abs(i.y-y));
	}
	return res;
}
void DFS(int x,int y){
	a[cnt].push_back({x,y});
	vis[x][y]=true;
	for (int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx<1 || ny<1 || nx>n || ny>m) continue;
		if (!vis[nx][ny] && c[nx][ny]=='X'){
			DFS(nx,ny);
		}
	}
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (!vis[i][j] && c[i][j]=='X'){
				cnt++;
				DFS(i,j);
			}
		}
	}
	d1=1e9,d2=1e9,d3=1e9;
	for (Point i:a[1]){
		for (Point j:a[2]){
			d1=min(d1,abs(i.x-j.x)+abs(i.y-j.y));
		}
	}
	for (Point i:a[1]){
		for (Point j:a[3]){
			d2=min(d2,abs(i.x-j.x)+abs(i.y-j.y));
		}
	}
	for (Point i:a[2]){
		for (Point j:a[3]){
			d3=min(d3,abs(i.x-j.x)+abs(i.y-j.y));
		}
	}
	ans=min(d1+d2-2,min(d1+d3-2,d2+d3-2));
	for (int x=1;x<=n;x++){
		for (int y=1;y<=m;y++){
			d1=getmin(x,y,1);
			d2=getmin(x,y,2);
			d3=getmin(x,y,3);
			ans=min(ans,d1+d2+d3-2);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
把两个斑点连起来，只需把两边各一个点连起来
	枚举所有点对(A,B)它们分属两个斑点
	找到距离最小的点对
有可能有内部的点，把他们也加入取最小值一定不是最优（一定会被淘汰），对答案无影响
分两类情况考虑：
一、记d1为一与二连，记d2为二与三连，记d3为三与一连，ans=min{d1+d2-2,d1+d3-2,d2+d3-2} （67分）
二、3块都与同一个点(x,y)连
	枚举x,y	(2500次)
		算x,y与a[1]内点的最小距离    用一个循环算
		a[2],a[3]的计算与a[1]同理
		ans=min(ans,d1+d2+d3-2);
*/
