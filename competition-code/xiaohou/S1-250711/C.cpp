#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct Node{
	int x,y;
};
vector<Node> G[N][N];
deque<Node> q;
int dis[N][N];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
bool check(int x1,int y1,int x2,int y2){
	for (Node v:G[x1][y1]){
		if (v.x==x2 && v.y==y2) return true;
	}
	return false;
}
int main(){
	memset(dis,0x3f,sizeof dis);
	int n,r;
	cin>>n>>r;
	for (int i=1;i<=r;i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		G[x1][y1].push_back({x2,y2});
		G[x2][y2].push_back({x1,y1});
	}
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	q.push_back({sx,sy});
	dis[sx][sy]=0;
	while(!q.empty()){
		Node now=q.front();
		q.pop_front();
		int x=now.x,y=now.y;
		for (int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n) continue;
			int w=check(x,y,nx,ny);
			if (dis[nx][ny]>dis[x][y]+w){
				dis[nx][ny]=dis[x][y]+w;
				if (w) q.push_back({nx,ny});
				else q.push_front({nx,ny});
			}
		}
	}
	cout<<dis[ex][ey]<<endl;
	return 0;
}
//68min