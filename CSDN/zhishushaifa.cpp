/*
1.普通筛法
所谓的筛法，就是把不是质数的筛去，剩下的数就都是质数了。对于两个大于1的整数i，j，i*j一定不是质数。由此我们可以得到一个质数的普通筛法。
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+5;
bool isPrime[N];
int main(){
    memset(isPrime,true,sizeof isPrime);
    for (int i=2;i<N;i++){
        for (int j=2*i;j<N;j+=i){
            isPrime[j]=false;
        }
    }
    return 0;
}
这个算法的时间复杂度是O(nlogn)，不难发现这个算法里面存在着一些重复计算。比如10即使2的倍数也是5的倍数，这样我们对于isPrime[10]就标记了两次，虽然对结果没有什么影响，但是再对于因数更多一点的数，我们在它身上耗费的时间就太多了。
通过观察，我们不难发现，一个合数必定要有一个质因子。那么如果我们只用质数进行筛查，这个效率就能提高了。这种想法正是我们接下来要讲的埃氏筛法。
2.埃氏筛法
埃氏筛法得名于古希腊数学家埃拉托塞尼（Eratosthenes），他计算了地球得周长，并且设计了现在为人熟知得经纬系统。
埃氏筛法的原理非常简单，从2开始，将每个质数的倍数标记成合数。时间复杂度为O(nlognlogn)。
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+5;
bool isPrime[N];
int main(){
    memset(isPrime,true,sizeof isPrime);
    for (int i=2;i<N;i++){
        if (isPrime[i]){
            for (int j=i*i;j<N;j+=i){
                isPrime[j]=false;
            }
        }
    }
    return 0;
}
3.线性筛 
在埃氏筛法中，一个合数x可能会被多个质因子筛选，例如12就既能被2筛选，又能被3筛选，但每个合数x只会被它最小的质因子筛选一次。如果将这些质因子按照从小到大的顺序一次枚举，那么就得到了线性筛法。时间复杂度为O(n)。
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+5;
bool isPrime[N];
int primes[N],cnt;
int main(){
    memset(isPrime,true,sizeof isPrime);
    for (int i=2;i<N;i++){
        if (isPrime[i]){
            primes[++cnt]=i;
        }
        for (int j=1;j<=cnt && primes[j]*i<N;j++){
            isPrime[i*primes[j]]=false;
            if (i%primes[j]==0) break;
        }
    }
    return 0;
}
*/