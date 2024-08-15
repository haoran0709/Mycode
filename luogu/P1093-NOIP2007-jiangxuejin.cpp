#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int tot[305],a[305],b[305],c[305],id[305];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		tot[i]=a[i]+b[i]+c[i];
		id[i]=i;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if ((tot[i]<tot[j])||(tot[i]==tot[j]&&a[i]<a[j])||(tot[i]==tot[j]&&a[i]==a[j]&&id[i]>id[j])){
				swap(id[i],id[j]);
				swap(tot[i],tot[j]);
				swap(a[i],a[j]);
			}
		}
	}
	for (int i=1;i<=5;i++){
		printf("%d %d\n",id[i],tot[i]);
	}
	return 0;
}