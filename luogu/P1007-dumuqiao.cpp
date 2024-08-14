#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=5e3+5;
int a[N]; 
int main(){
	int len,n;
	cin>>len>>n;
	//comments added
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=0,now=0;
	for (int i=1;i<=n;i++){
		if (a[i]<=len/2){
			l=a[i];
		}
		else{
			if (now==0) now=a[i];
			r=a[i];
		}
	}
	if (l==0 && r==0) cout<<"0 0\n"; 
	else if (l==0) cout<<max(len-r+1,l)<<" "<<r;
	else if (r==0) cout<<max(len-r+1,l)<<" "<<l;
	else cout<<max(len-now+1,l)<<" "<<max(len+1-a[1],a[n]);
	return 0;
}
//z=2;
//n n n n 5