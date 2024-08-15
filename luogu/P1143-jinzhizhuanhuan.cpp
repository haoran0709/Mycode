#include <cstdio>
#include <iostream>
using namespace std;
char d[105];
char e[105];
char t(int r){
	if (r>=10) return 'A'+(r-10);
	return '0'+r;
}
int qpow(int a,int b){
	if (b==0) return 1;
	int c=1;
	for (int i=1;i<=b;i++)  c*=a;
	return c;
}
int main(){
	int a,b,cnt=0,ans=0;
	string s;
	cin>>a>>s>>b;
	int len=s.length();
	for (int i=0;i<s.length();i++){
		int x=0,c=0;
		if (s[i]>='A') x=9+(s[i]-'A')+1;
		else x=s[i]-'0';
		ans+=x*qpow(a,len-i-1);
		//cout<<ans<<endl;
	}
	//cout<<ans<<endl;
	while(ans>0){
		//cout<<cnt<<" "<<ans<<endl;
		d[++cnt]=t(ans%b);
		ans/=b;
	}
	for (int i=cnt;i>=1;i--) cout<<d[i];
	return 0;
}