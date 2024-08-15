#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=400+5;
struct Node{
	int x,y;
}s;
int d[N][N];
int dx[10]={1,-1,1,-1,2,-2,2,-2};
int dy[10]={-2,2,2,-2,1,1,-1,-1};
queue<Node> q;
int main() {
	memset(d,-1,sizeof d);
	int n,m;
	cin>>n>>m;
	cin>>s.x>>s.y;
	d[s.x][s.y]=0;
	q.push({s.x,s.y});
	while(!q.empty()){
		Node now=q.front();
		q.pop();
		for (int i=0;i<8;i++){
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (d[nx][ny]==-1){
				d[nx][ny]=d[now.x][now.y]+1;
				q.push({nx,ny});
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			printf("%-5d",d[i][j]);
		}
		cout<<endl;
	}
    return 0;
}