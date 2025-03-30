#include <bits/stdc++.h>
using namespace std;
const int N=25+5;
const int M=1e4+5;
int a[N];
long long f[M];
int main(){
	int n,m;
	cin>>n>>m;
	f[0]=1;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		for (int j=a[i];j<=m;j++){
			f[j]+=f[j-a[i]];
		}
	}
	//for (int i=1;i<=m;i++) cout<<f[i]<<" ";
	cout<<f[m]<<endl;
	return 0;
}