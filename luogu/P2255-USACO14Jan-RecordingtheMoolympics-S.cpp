#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=155;
struct Time{
	long long a,b;
}d[N];
bool cmp(Time A,Time B){
	return A.b < B.b;
}
int main(){
	long long n,cnt=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>d[i].a>>d[i].b;
	sort(d+1,d+n+1,cmp);
	long long x=0,y=0;
	for (int i=1;i<=n;i++){
		//printf("d[%d].a=%d,d[%d].b=%d,x=%d,y=%d\n",i,d[i].a,i,d[i].b,x,y);
		if (d[i].a<x) continue;
		else if (d[i].a >= y){
			cnt++;
			y=d[i].b;
		}
		else{
			cnt++;
			x=d[i].b;
		}
		if (x>y) swap(x,y);
	}
	cout<<cnt<<endl;
}
// 6
// 0 3
// 1 5
// 3 10
// 6 7