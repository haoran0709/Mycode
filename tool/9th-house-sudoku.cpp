#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=15;
int a[N][N],n;
bool c[N][N],r[N][N],g[5][5][N];
void DFS(int x,int y){
	if (x>9){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				cout<<a[i][j]<<" \n"[j==n];
			}
		}
		exit(0);
	}
	if (a[x][y]!=0){
		if (y+1>n) DFS(x+1,1);
		else DFS(x,y+1);
	}
	else{
		for (int i=1;i<=n;i++){
			if (!g[(x-1)/3+1][(y-1)/3+1][i] && !c[y][i] && !r[x][i]){
				a[x][y]=i;
				g[(x-1)/3+1][(y-1)/3+1][i]=c[y][i]=r[x][i]=true;
				if (y+1>n) DFS(x+1,1);
				else DFS(x,y+1);
				g[(x-1)/3+1][(y-1)/3+1][i]=c[y][i]=r[x][i]=false;
				a[x][y]=0;//*
			}
		}
	}
}
int main(){
	n=9;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			if (a[i][j]!=0){
				g[(i-1)/3+1][(j-1)/3+1][a[i][j]]=c[j][a[i][j]]=r[i][a[i][j]]=true;
			}
		}
	}
	DFS(1,1);
	return 0;
}