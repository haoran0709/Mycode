#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=3*1e4+5;
int a[N],cnt;
int main(){
	int w,n;
	cin>>w>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1,j=n;i<=j;j--){
		if (a[j]+a[i]>w) cnt++; 
		if (a[j]+a[i]<=w){
			cnt++;
			i++;
		}
	} 
	cout<<cnt<<endl;
	return 0;
}


//177
//14
//
//
//
//
//
//81 83
//109
//114
//115
//117 47
//121 41
//122 40
//157
//159 8

