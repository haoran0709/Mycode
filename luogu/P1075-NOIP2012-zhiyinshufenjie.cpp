#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	for (int i=2;i*i<=n;i++){
		if (n%i){
			continue;	
		}
		while (!(n%i)){
			n/=i;
		}
	}
	printf("%d",n);
	return 0;
}
