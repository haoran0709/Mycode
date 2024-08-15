#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
const int N=25;
int n,r,a[N];
void DFS(int step,int last){
	if (step > r){
		for (int i=1;i<=r;i++){
			cout<<setw(3)<<a[i]; 
		}
		cout<<endl;
		return ;
	}
	for (int i=last+1;i<=n;i++){
		a[step]=i;
		DFS(step+1,i);
	}
}
int main(){
	cin>>n>>r;
	DFS(1,0);
	return 0;
}