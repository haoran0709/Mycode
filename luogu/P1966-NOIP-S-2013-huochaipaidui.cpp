#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e8-3;
struct Match{
	int id,h;
}p[N],q[N];
int pos[N],b[N],c[N];
long long ans;
bool cmp(Match A,Match B){
	return A.h < B.h;
}
void merge(int a[],int l,int r){
	int mid=(l+r)/2;
	int x=0,y=0;
	for (int i=l;i<=mid;i++) b[++x]=a[i];
	for (int i=mid+1;i<=r;i++) c[++y]=a[i];
	b[x+1]=c[y+1]=2e9;
	for (int i=l,j=1,k=1;i<=r;i++){
		if (b[j] < c[k]) a[i]=b[j++];
		else{
			a[i]=c[k++];
			ans=(ans+x-j+1+mod)%mod;
		}
	}
}
void mergesort(int a[],int l,int r){
	if (l==r) return ;
	int mid=(l+r)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
	merge(a,l,r);
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>p[i].h;
		p[i].id=i;
	}
	for (int i=1;i<=n;i++){
		cin>>q[i].h;
		q[i].id=i;
	}
	sort(p+1,p+n+1,cmp);
	sort(q+1,q+n+1,cmp);
	for (int i=1;i<=n;i++) pos[p[i].id]=q[i].id;
	mergesort(pos,1,n);
	cout<<ans<<endl;
	return 0;
}