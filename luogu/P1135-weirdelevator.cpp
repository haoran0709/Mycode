#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int n,a,b,d[205],y,x,k[205];
queue<int> q;
int main(){
	cin>>n>>a>>b;
	for (int i=1;i<=n;i++) cin>>k[i];
	memset(d,-1,sizeof d);
	d[a]=0;
	q.push(a);
	while(!q.empty()){
		x=q.front();
		q.pop();
		y=x+k[x];
		if (d[y]==-1 && y>0 && y<=n){
			q.push(y);
			d[y]=d[x]+1;
		}
		y=x-k[x];
		if (d[y]==-1 && y>0 && y<=n){
			q.push(y);
			d[y]=d[x]+1;
		}
	}
	cout<<d[b]-d[a]<<endl;
	return 0;
}