// 2022.08.17

#include<bits/stdc++.h>
using namespace std;

int n,dcnt,tot[1000001];
long long d[1000001],a[1000001],ans;

int main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int t=1;t<=12;t++){
		long long x=a[(((long long)rand()<<31)|rand())%n+1];
		dcnt=0;
		for(long long i=1;i*i<=x;i++)
			if(x%i==0){
				d[++dcnt]=i;
				if(i*i!=x)d[++dcnt]=x/i;
			} 
		sort(d+1,d+1+dcnt);
		memset(tot,0,sizeof tot);
		for(int i=1;i<=n;i++)
			tot[lower_bound(d+1,d+1+dcnt,__gcd(x,a[i]))-d]++;
		for(int i=1;i<dcnt;i++)
			for(int j=i+1;j<=dcnt;j++)
				if(d[j]%d[i]==0)tot[i]+=tot[j];
		for(int i=1;i<=dcnt;i++)
			if((tot[i]<<1)>=n)ans=max(ans,d[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
