#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int main(){
	int a,b,l,ans_a=1e9,ans_b=1;
	cin>>a>>b>>l;
	for (int i=1;i<=l;i++){
		for (int j=1;j<=l;j++){
			if (gcd(i,j)!=1) continue;
			if (1.0*i/j >= 1.0*a/b && (1.0*i/j-1.0*a/b)<(1.0*ans_a/ans_b-1.0*a/b)){
				ans_a=i;
				ans_b=j;
			}
		}
	}
	cout<<ans_a<<" "<<ans_b<<endl;
	return 0;
}