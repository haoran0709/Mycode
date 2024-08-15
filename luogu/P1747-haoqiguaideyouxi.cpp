#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N=20+5;
int dx[13]={1,1,-1,-1,2,2,-2,-2,2,-2,-2,2};
int dy[13]={-2,2,-2,2,1,-1,-1,1,2,2,-2,-2};
int d[N][N];
struct Node{
	int x,y;
};
queue<Node> q;
int main(){
	memset(d,-1,sizeof d);
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int n=max(x1,x2);
	int m=max(y1,y2);
	d[1][1]=0;
	q.push({1,1});
	while(!q.empty()){
		Node now=q.front();
		q.pop();
		for (int i=0;i<12;i++){
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if (nx<1 || ny<1 || nx>25 || ny>25) continue;
			if (d[nx][ny]==-1){
				q.push({nx,ny});
				d[nx][ny]=d[now.x][now.y]+1;
			}
		}
	}
	cout<<d[x1][y1]<<endl;
	cout<<d[x2][y2]<<endl;
	return 0;
}