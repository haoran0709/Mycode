#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int a[N];
int main(){
	int n,cnt=0,ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	cnt/=n;
	for (int i=1;i<=n;i++){
		if (a[i]!=cnt){
			// if (a[i-1]>a[i+1] && a[i-1]>cnt){
			// 	a[i]+=a[i-1]-cnt;
			// 	a[i-1]=cnt;
			// 	ans++;
			// }
			// else{
				a[i+1]-=cnt-a[i];
				a[i]=cnt;
				ans++;
			//}
		}
	}
	cout<<ans<<endl;
	return 0;
}