#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int n,l,r,now=0;
    cin>>n>>l>>r;
    if (l/n == r/n) cout<<r%n<<endl;
    else cout<<n-1<<endl;
    return 0;
}