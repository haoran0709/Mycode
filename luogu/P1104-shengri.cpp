#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Person{
	string name;
	int y,m,d,id;
}a[105];
bool cmp(Person A,Person B){
	if (A.y!=B.y) return A.y < B.y;
	if (A.m!=B.m) return A.m < B.m;
	if (A.d!=B.d)return A.d < B.d;
	return A.id > B.id;
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].y>>a[i].m>>a[i].d; 
		a[i].id=i; 
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) cout<<a[i].name<<endl;
	return 0;
}