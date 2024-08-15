#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e4+5;
int a[N];
int main(){
	int ans=0,n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (a[i]>a[j]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}