// 2022.08.02

#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;

long long power(long long m,long long n=mod-2){
	if(n==0)return 1;
	long long tmp=power(m,n>>1);
	tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*m%mod;
	return tmp;
}

long long fac[2000001],invfac[2000001];
void init(int N=2000000){
	fac[0]=1;
	for(int i=1;i<=N;i++)
		fac[i]=fac[i-1]*i%mod;
	invfac[N]=power(fac[N]);
	for(int i=N-1;i>=0;i--)
		invfac[i]=invfac[i+1]*(i+1)%mod;
}
inline long long C(int n,int m){
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
inline long long Catalan(int n,int m){
	return (C(n+m,m)-C(n+m,m-1)+mod)%mod;
}

inline int getlineid(long long u){
	int l=1,r=1000000;
	while(l<r){
		int mid=l+r>>1;
		if(mid*(mid+1ll)/2>=u)r=mid;
		else l=mid+1;
	}
	return l;
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		long long u,answer=0;
		scanf("%lld",&u);
		int x=getlineid(u)-1,y=u-x*(x+1ll)/2-1;
		for(int i=0;i<=y;i++)
			answer+=Catalan(x-i,y-i)*C(x+y-i,i)%mod,answer%=mod;
		printf("%lld\n",answer);
	}
	return 0;
}
