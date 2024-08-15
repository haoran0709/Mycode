#include <iostream>
#include <cstdio>
using namespace std;
const int N=10+5;
char a[N][N],b[N][N],ne[N][N];
int n;
bool check_1(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ne[j][n-i+1]=a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (ne[i][j]!=b[i][j]) return false;
		}
	}
	return true;
}
bool check_2(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ne[n-i+1][n-j+1]=a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (ne[i][j]!=b[i][j]) return false;
		}
	}
	return true;
}
bool check_3(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ne[n-j+1][i]=a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (ne[i][j]!=b[i][j]) return false;
		}
	}
	return true;
}
bool check_4(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ne[i][n-j+1]=a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (ne[i][j]!=b[i][j]) return false;
		}
	}
	return true;
}
bool check_5(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ne[i][n-j+1]=a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			a[i][j]=ne[i][j];
		}
	}
	if (check_1()) return true;
	if (check_2()) return true;
	if (check_3()) return true;
	return false;
}
bool check_6(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i][j]!=b[i][j]) return false;
		}
	}
	return true;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){	
			cin>>b[i][j];
		}
	}
	if (check_1()) cout<<1<<endl;
	else if (check_2()) cout<<2<<endl;
	else if (check_3()) cout<<3<<endl;
	else if (check_4()) cout<<4<<endl;
	else if (check_6()) cout<<6<<endl;
	else if (check_5()) cout<<5<<endl;
	else cout<<7<<endl;
	return 0;
}