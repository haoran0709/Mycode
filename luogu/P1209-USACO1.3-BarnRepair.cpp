#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200+5;
int a[N],b[N];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	int m,s,c;
	cin>>m>>s>>c;
	for (int i=1;i<=c;i++) cin>>a[i];
	sort(a+1,a+c+1);//***
	for (int i=1;i<=c-1;i++){
		b[i]=a[i+1]-a[i]-1;//***
	}
	sort(b+1,b+c,cmp);
	int ans=a[c]-a[1]+1;
	for (int i=1;i<=m-1;i++){
		ans-=b[i];
	}
	cout<<ans<<endl;
	return 0;
}
// 6     3~8
// 8     14~21
// 7     25~31
// 4     40~43
