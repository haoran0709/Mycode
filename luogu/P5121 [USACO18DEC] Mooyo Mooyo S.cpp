#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cstring>
using namespace std;
const int N=100+5;
char a[N][15];
bool f[N][15];
int n,k,tot;
int cnt[N*10],id[N][15];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
void Print(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=10;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
void DFS(int x,int y){
	cnt[tot]++;
	id[x][y]=tot;
	f[x][y]=true;
	for (int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx<1 || ny<1 || nx>n || ny>10) continue;
		if (a[nx][ny]!=a[x][y]) continue;
		if (a[nx][ny]!='0' && !f[nx][ny]){
			DFS(nx,ny);
		}
	}
}
bool check(){
	memset(f,false,sizeof f);
	memset(cnt,0,sizeof cnt);
	bool flag=false;
	tot=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=10;j++){
			if (a[i][j]!='0' && !f[i][j]){
				tot++;
				DFS(i,j);
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=10;j++){
			if (cnt[id[i][j]]>=k){
				flag=true;
				a[i][j]='0';
			}
		}
	}
	return flag;
}
void Down(){
	for (int j=1;j<=10;j++){
		int x=n;
		for (int i=n;i>=1;i--){
			if (a[i][j]!='0'){
				swap(a[i][j],a[x--][j]);
			}
		}
	}
}
int main() {
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=10;j++){
			cin>>a[i][j];
		}
	}
	while(check()){
		Down();
		//Print();
	}
	Print();
    return 0;
}