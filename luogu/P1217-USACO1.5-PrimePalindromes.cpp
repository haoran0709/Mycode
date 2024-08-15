#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int call(int x){
	int t=0;
	do{
		t=t*10+x%10;
		x/=10;
	}while(x);
	return t;
}
bool isPream(int a){
	if (a<=1){
		return false;
	}
	for (int i=2;i*i<=a;i++){
		if (a%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	b=min(b,9999999);
	for (int i=a;i<=b;i++){
		if (i==call(i)&&isPream(i)){
			printf("%d\n",i);
		}
	}
	return 0;
}