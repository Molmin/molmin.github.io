// 2022.08.16

#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

long long power(long long x,long long t=mod-2){
	long long tmp=1;
	for(;t;t>>=1,x=x*x%mod)
		if(t&1)tmp=tmp*x%mod;
	return tmp;
}

struct point{
	int x,y;
	void read(){
		int a,b;
		scanf("%d%d",&a,&b);
		x=a+b,y=a-b;
	}
}t,A[1001],B[1001],C[1001];
int anum,bnum,cnum;

long long fac[3001],invf[3001];
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*(long long)i%mod;
	invf[n]=power(fac[n]);
	for(int i=n-1;i>=0;i--)
		invf[i]=invf[i+1]*(i+1ll)%mod;
}
long long calC(int n,int m){
	if(m<0||m>n)return 0;
	return 1ll*fac[n]*invf[m]%mod*invf[n-m]%mod;
}

int m; long long f[6001];
point p[1001]; int cnt;
long long work(bool ha,bool hb,bool hc){
	cnt=0;
	if(ha)for(int i=1;i<=anum;i++)
		p[++cnt]=A[i];
	if(hb)for(int i=1;i<=bnum;i++)
		p[++cnt]=B[i];
	if(hc)for(int i=1;i<=cnum;i++)
		p[++cnt]=C[i];
	int tmp=-1;
	for(int i=1;i<=cnt;i++)
		if((p[i].x&1)!=tmp){
			if(tmp==-1)tmp=p[i].x&1;
			else return 0;
		}
	tmp=-1;
	for(int i=1;i<=cnt;i++)
		if((p[i].y&1)!=tmp){
			if(tmp==-1)tmp=p[i].y&1;
			else return 0;
		}
	int minx=114514,maxx=-114514,miny=114514,maxy=-114514;
	for(int i=1;i<=cnt;i++)
		minx=min(minx,p[i].x),maxx=max(maxx,p[i].x),
		miny=min(miny,p[i].y),maxy=max(maxy,p[i].y);
	for(int x=maxx-m;x<=minx+m;x++){
		f[x+3000]=1;
		for(int i=1;i<=cnt;i++)
			f[x+3000]=f[x+3000]*(m-x+p[i].x)%mod
				*power(m+x-p[i].x+2)%mod;
	}
	long long answer=0;
	for(int y=maxy-m;y<=miny+m;y+=2){
		long long tmp=1;
		for(int i=1;i<=cnt;i++)
			tmp=tmp*calC(m,m-y+p[i].y>>1)%mod*
				calC(m,m+(p[i].x-maxx>>1))%mod;
		for(int x=maxx-m;x<=minx+m;x+=2){
			answer+=tmp,answer%=mod;
			tmp*=f[x+3000],tmp%=mod;
		}
	}
	return answer;
}

int main(){
	freopen("pretend.in","r",stdin);
	freopen("pretend.out","w",stdout);
	init(3000);
	int n;
	scanf("%d%d%d%d",&n,&anum,&bnum,&m);
	cnum=n-anum-bnum;
	for(int i=1;i<=anum;i++)A[i].read();
	for(int i=1;i<=bnum;i++)B[i].read();
	for(int i=1;i<=cnum;i++)C[i].read();
	long long answer=0,ansA,ansB,ansC;
	ansA=work(1,0,0),ansB=work(0,1,0),ansC=work(0,0,1);
	answer=ansA*ansB%mod*ansC%mod;
	answer-=work(1,1,0)*ansC%mod;
	answer-=work(0,1,1)*ansA%mod;
	answer-=work(1,0,1)*ansB%mod;
	answer+=(work(1,1,1)<<1)%mod;
	answer=answer%mod+mod,answer%=mod;
	printf("%lld\n",answer);
	return 0;
}
