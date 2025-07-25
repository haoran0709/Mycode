#include <bits/stdc++.h>
using namespace std;
const int N=50+5;
int a[N][N],f[N][N][5];
//f数组升维
struct Node{
	int x,y,c;
}s,e;
queue<Node> q;
int dx[5]={0,1,-1,0};//start:E
int dy[5]={1,-0,0,-1};
int work(int now,int x){
    now=now+4+x;
    return now%4;
}
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
            for (int k=0;k<4;k++) f[i][j][k]=1e9;
		}
	}
	char c;
	cin>>s.x>>s.y>>e.x>>e.y>>c;
	int x;
	if (c=='E') x=0;
	else if (c=='S') x=1;
	else if (c=='W') x=2;
	else if (c=='N') x=3;
	s.c=x;
	q.push({s});
	f[s.x][s.y][x]=0;
	while(!q.empty()){
		Node now=q.front();
		printf("x=%d,x=%d,c=%d,f=%d\n",now.x,now.y,now.c,f[now.x][now.y][now.c]);
		q.pop();
		int nx,ny,op;
		for (int i=1;i<=3;i++){
			nx=now.x+dx[now.c]*i;
			ny=now.y+dy[now.c]*i;
			if (nx>n || ny>m || nx<1 || ny<1) continue;
			if (f[nx][ny][now.c]==1e9) q.push({nx,ny,now.c});
			f[now.x][now.y][now.c]=min(f[now.x][now.y][now.c],f[nx][ny][now.c]+1);
		}
		//left
		op=work(now.c,-1);
		nx=now.x;
		ny=now.y;
		if (nx>n || ny>m || nx<1 || ny<1) continue;
		if (f[nx][ny][op]==1e9) q.push({nx,ny,op});
		f[now.x][now.y][now.c]=min(f[now.x][now.y][now.c],f[nx][ny][op]+1);
		//right
		op=work(now.c,1);
		nx=now.x;
		ny=now.y;
		if (nx>n || ny>m || nx<1 || ny<1) continue;
		if (f[nx][ny][op]==1e9) q.push({nx,ny,op});
		f[now.x][now.y][now.c]=min(f[now.x][now.y][now.c],f[nx][ny][op]+1);
	}
    cout<<f[e.x][e.y]<<endl;
	return 0;
}