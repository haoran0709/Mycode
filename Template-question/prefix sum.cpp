#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100005],res[100005];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
        cin>>a[i];
        res[i]=res[i-1]+a[i];
    }
	int q,l,r;
	cin>>q;
	for (int i=1;i<=q;i++){
		cin>>l>>r;
		cout<<res[r]-res[l-1]<<endl;
	}
	return 0;
}