// 2022.06.12

#include<bits/stdc++.h>
using namespace std;

int n,m,s;

struct Edge{
	int u,v,w;
	inline bool operator<(Edge tmp)const{
		return w<tmp.w;
	}
};
vector<Edge>edge;

int deg[2501];

struct{
	int f[2501];
	void init(int N){
		for(int i=1;i<=N;i++)f[i]=i;
	}
	int find(int id){
		if(f[id]!=id)f[id]=find(f[id]);
		return f[id];
	}
	void merge(int u,int v){
		f[find(u)]=find(v);
	} 
}a,b;

long long sum;

int main(){
	scanf("%d%d%d",&n,&m,&s);
	a.init(n);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++,deg[v]++;
		a.merge(u,v);
		sum+=abs(u-v);
	}
	for(int i=1;i<=n;i++)
		a.f[i]=a.find(i);
	for(int i=1;i<=n;i++){
		b.init(n);
		deg[s]++,deg[i]++;
		b.merge(a.f[s],a.f[i]);
		long long answer=sum;
		int Last=0;
		for(int j=1;j<=n;j++)
			if(deg[j]&1)
				if(Last==0)Last=j;
				else{
					answer+=abs(j-Last);
					for(int k=Last;k<j;k++)
						b.merge(a.f[k],a.f[k+1]);
					Last=0;
				}
		edge.clear();
		Last=0;
		for(int j=1;j<=n;j++)
			if(deg[j]){
				if(Last&&b.find(a.f[Last])!=b.find(a.f[j]))
					edge.push_back({a.f[Last],a.f[j],abs(j-Last)});
				Last=j;
			}
		sort(edge.begin(),edge.end());
		for(Edge e:edge)
			if(b.find(e.u)!=b.find(e.v)){
				b.merge(e.u,e.v);
				answer+=e.w*2;
			}
		printf("%lld ",answer);
		deg[s]--,deg[i]--;
	}
	return 0;
} 
