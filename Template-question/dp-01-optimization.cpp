#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int w[N],v[N],f[N];
int main() {
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>w[i]>>v[i];
	for (int i=1;i<=n;i++){
		for (int j=m;j>=w[i];j--){
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	cout<<f[m]<<endl;
    return 0;
}