#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
char R(int x){
	if (x <= 9) return x+'0';
	x-=9;
	return 'A'+(x-1);
}
int main(){
	int n;
	cin>>n;
	int r;
	cin>>r;
	string ans;
	while (n) {
		ans+=R(n%r);
		n /= r;
	}
	for (int i=ans.length()-1;i>=0;i--) cout<<ans[i];
	return 0;
}