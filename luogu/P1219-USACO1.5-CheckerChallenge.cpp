#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=45;
const int p=20;
int n;
int a[N],ans;
bool c[N],l[N],r[N];
void DFS(int step){
	if (step > n){
		ans++;
		if (ans<=3) for (int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
		return ;
	}
	for (int i=1;i<=n;i++){
		if (!c[i] && !l[i-step+p] && !r[i+step]){
			a[step]=i;
			c[i]=true;
			l[i-step+p]=true;
			r[i+step]=true;
			DFS(step+1);
			c[i]=false;
			l[i-step+p]=false;
			r[i+step]=false;
		}
	}
}
int main(){
	cin>>n;
	DFS(1);
	cout<<ans<<endl;
	return 0;
}