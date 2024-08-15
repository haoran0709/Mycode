#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	if (b==0) return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
int main() {
	long long a,b;
    cin>>a>>b;
    printf("gcd:%lld,lcm:%lld\n",gcd(a,b),lcm(a,b));
    return 0;
}
