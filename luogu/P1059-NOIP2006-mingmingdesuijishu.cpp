#include <cstdio>
using namespace std;
int a[105];
int n,m,t,x,cnt;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (a[i]>a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (x!=a[i]){
			x=a[i];
			cnt++;
		}
		else a[i]=0;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++){
		if (a[i]!=0) printf("%d ",a[i]);
	}
	return 0;
}
