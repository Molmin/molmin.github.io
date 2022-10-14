本题即求 Catalan 数，难点在于模数 $p$ 不一定为素数。

卡特兰数 $C_n=\dfrac{\dbinom{2n}n}{n+1}=\dfrac{(2n)!}{n!\cdot (n+1)!}$。

考虑求出对于每个素数 $p$，答案中有多少个素因子 $p$。

### 法 1

使用公式

$$
v_p(n!)=\sum_{i=1}^\infty\left[\frac n{p^i
}\right]
$$

直接计算：

$$
v_p(C_n)=v_p((2n)!)-v_p(n!)-v_p((n+1)!).
$$

```c++
// 2022.08.02

#include<bits/stdc++.h>
using namespace std;
int p;

long long power(long long m,long long n=p-2){
    if(n==0)return 1;
    long long tmp=power(m,n>>1);
    tmp=tmp*tmp%p;
    if(n&1)tmp=tmp*m%p;
    return tmp;
}

bool isp[2000001];
int cnt,prime[150000];
void getprimes(int N=2000000){
    memset(isp,true,sizeof isp);
    isp[0]=isp[1]=false;
    for(int i=2;i<=N;i++)
        if(isp[i]){
            prime[++cnt]=i;
            for(int j=i<<1;j<=N;j+=i)
                isp[j]=false;
        }
}
inline int Vp(int pid,int n){
    int cnt=0;
    while(n)cnt+=n/prime[pid],n/=prime[pid];
    return cnt;
}

int main(){
    int n;
    scanf("%d%d",&n,&p);
    getprimes();
    long long answer=1;
    for(int i=1;i<=cnt&&prime[i]<(n<<1);i++)
        answer=answer*power(prime[i],Vp(i,n<<1)-Vp(i,n+1)-Vp(i,n))%p;
    printf("%lld\n",answer);
	return 0;
}
```

### 法 2

法 1 是相比法 2 较笨拙的一种方法，但是比较容易想到。

令 $v_i$ 表示答案中 $i$ 的乘积个数。则初始

$$
v_i\gets
\begin{cases} 
1,  & \text{if }n+2\leq i\leq 2n \\
0, & \text{if }i=n+1 \\
-1, & \text{if }1\leq i\leq n
\end{cases}.
$$

接着令 $i$ 到序遍历 $[2,\ 2n]$ 中的整数。若 $i$ 为素数，就不进行操作；若 $i$ 为合数，就对它进行拆分，即令 $p=\max\limits_{j|i,\ 0<j\in\Bbb{P}}j$，则

$$
\begin{aligned}
v_p & \gets v_p+v_i \\
v_\frac ip & \gets v_\frac ip+v_i \\
v_i & \gets 0
\end{aligned}
$$

即可。

其中 $\max\limits_{j|i,\ 0<j\in\Bbb{P}}j$ 可以先用欧拉筛预处理。可以证明，时间复杂度约为 $\Theta(n)$。
