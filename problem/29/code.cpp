// 2022.08.02

#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;

long long power(long long m,long long n=mod-2){
    if(n==0)return 1;
    long long tmp=power(m,n>>1);
    tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*m%mod;
    return tmp;
}

long long fac(int n){
    long long res=1;
    for(int i=1;i<=n;i++)
        res=res*i%mod;
    return res;
}
long long C(int n,int m){
    if(m>n)return 0;
    return fac(n)*power(fac(m))%mod*power(fac(n-m))%mod;
}

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    if(n>m+k)return printf("0\n"),0;
    printf("%lld\n",(C(n+m,m)-C(n+m,m+k+1)+mod)%mod);
	return 0;
}
