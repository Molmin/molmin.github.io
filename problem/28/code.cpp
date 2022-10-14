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

int cnt,prime[150000],maxp[2000001];
void getprimes(int N=2000000){
    for(int i=2;i<=N;i++){
        if(maxp[i]==0)prime[++cnt]=i,maxp[i]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=N;j++){
            maxp[prime[j]*i]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
}

int v[2000001];

int main(){
    int n;
    scanf("%d%d",&n,&p);
    getprimes();
    for(int i=1;i<=n;i++)v[i]=-1;
    for(int i=n+2;i<=(n<<1);i++)v[i]=1;
    for(int i=(n<<1);i>=2;i--)
        if(maxp[i]!=i)v[maxp[i]]+=v[i],v[i/maxp[i]]+=v[i],v[i]=0;
    long long answer=1;
    for(int i=1;i<=cnt&&prime[i]<(n<<1);i++)
        answer=answer*power(prime[i],v[prime[i]])%p;
    printf("%lld\n",answer);
	return 0;
}
