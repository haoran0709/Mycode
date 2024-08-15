#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	char c;
	int A=0,B=0;
	int flag=1,f=1,t=0;
	char w;
	while(cin>>c){
		if (isalpha(c)){
			w=c;
			A+=flag*f*max(t,1);
			t=0;
		}
		else if (isdigit(c)){
			t=t*10+(c-'0');
		}
		else{
			B+=flag*f*t;
			t=0;
		}
		if (c=='-') f=-1;
		else if (c=='+') f=1;
		else if (c=='='){
			flag=-1;
			f=1;
		}
	}
	B+=flag*f*t;
	if (B==0) printf("%c=0.000\n",w);
	else printf("%c=%.3lf\n",w,-1.0*B/A);
	return 0;
}