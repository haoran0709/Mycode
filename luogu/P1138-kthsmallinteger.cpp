#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int cnt[30005];
int main(){
	int n,k,res=0,x;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>x;
		cnt[x]++;
	}
	for (int i=1;i<=30000;i++){
		if (cnt[i]==0) continue;
		res++;
		if (res==k){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"NO RESULT";
	return 0;
}