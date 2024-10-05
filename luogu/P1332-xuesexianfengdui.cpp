#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
struct Node{
	int x,y;
};
queue<Node> q;
int d[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
	memset(d,-1,sizeof d);
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	for (int i=1;i<=a;i++){
		int x,y;
		cin>>x>>y;
		d[x][y]=0;
		q.push({x,y});
	}
	while (!q.empty()){
		Node now=q.front();
		q.pop();
		for (int i=0;i<4;i++){
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (d[nx][ny]==-1){
				d[nx][ny]=d[now.x][now.y]+1;
				q.push({nx,ny});
			}
		}
	}
	for (int i=1;i<=b;i++){
		int x,y;
		cin>>x>>y;
		cout<<d[x][y]<<endl;
	}
	return 0;
}