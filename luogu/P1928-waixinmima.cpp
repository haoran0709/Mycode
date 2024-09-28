#include <cstdio>
#include <iostream>
using namespace std;
string solve(){
    char c;
    int x=0;
    string res;
    while(cin>>c){
    	//if (c=='/') break;
        if (isdigit(c)) x=x*10+(c-'0');
        if (isalpha(c)) res=res+c;
        if (c=='[') res=res+solve();
        if (c==']'){
        	string t;
            for (int i=1;i<=x;i++) t=t+res;
            res=t;
        	return res;
		}
    }
    if (x==0) x=1;
    string t;
    for (int i=1;i<=x;i++) t=t+res;
    res=t;
    return res;
}
int main(){
    cout<<solve()<<endl;
    return 0;
}
//[2[2[2NOTOMAMIKO]]]
//