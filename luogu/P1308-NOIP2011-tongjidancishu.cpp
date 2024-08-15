#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,x;
    getline(cin,x);
    getline(cin,s);
    //大写转小写
    for (int i=0;i<x.length();i++) if('A'<=x[i] && x[i]<='Z') x[i]+='a'-'A';
    for (int i=0;i<s.length();i++) if('A'<=s[i] && s[i]<='Z') s[i]+='a'-'A';
    //计算第1次出现的位置
    int found1=-1;
    int ans=0;
    int last;
    bool flag=true;
    for (int i=0;i<s.length();i++){
    	string q="";
    	if (flag){
    		q+=s[0];
    		flag=false;
    	}
    	last=i;
    	while (s[last+1]!=' ' && last+1<s.length()){
    		last++;
    		q+=s[last];
    	}
    	if (q==x) {
    		found1=i+1;
    		break;
    	}
    	i=last;
    }
    int found=found1;
    //统计出现的总次数
    flag=true;
    int cnt=0;
    ans=1;
    for (int i=0;i<s.length();i++){
    	string q="";
    	last=i;
    	if (flag){
    		q+=s[0];
    		flag=false;
    	}
    	while (s[last+1]!=' ' && last+1<s.length()){
    		last++;
    		q+=s[last];
    	}
    	if (q==x) cnt++;
    	i=last;
    }
    //输出
    if (found1==-1) cout<<"-1"<<endl;
    else cout<<cnt<<" "<<found1<<endl;
    return 0;
}