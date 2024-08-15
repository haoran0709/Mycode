#include<cstdio>
#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
const int N=1e3+5;
const int M=1e6+5;
int n,m,tot;
int a[N][N],id[N][N],cnt[M];
bool f[N][N];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
void DFS(int x,int y,int col){
	cnt[tot]++;
	id[x][y]=tot;
	f[x][y]=true;
	for (int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx<1 || ny<1 || nx>n || ny>n) continue;
		if (!f[nx][ny] && a[nx][ny]==col){
			DFS(nx,ny,!col);
		}
	}
}
void MAIN(){
	int x,y;
	cin>>x>>y;
	cout<<cnt[id[x][y]]<<endl;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		string s;
		cin>>s;
		s=' '+s;
		for (int j=1;j<=n;j++){
			a[i][j]=s[j]-'0';
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (!f[i][j]){
				tot++;
				DFS(i,j,!a[i][j]);
			}
		}
	}
	for (int i=1;i<=m;i++) MAIN();
	return 0;
}