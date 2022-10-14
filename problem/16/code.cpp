// 2022.07.26

#include<bits/stdc++.h>
using namespace std;

int n,q,f[300001];

struct Edge{
	int to,nxt;
}edge[600001];
int cntEdge,head[300001];
inline void addEdge(int u,int v){
	edge[++cntEdge]={v,head[u]},head[u]=cntEdge;
}

int siz[300001],g[300001];
void dp(int id){
	siz[id]=1;
	for(int i=head[id];i;i=edge[i].nxt)
		if(edge[i].to!=f[id]){
			dp(edge[i].to);
			siz[id]+=siz[edge[i].to];
		}
	int maxn=0;
	for(int i=head[id];i;i=edge[i].nxt)
		if(edge[i].to!=f[id]){
			int v=edge[i].to;
			if((siz[v]<<1)>=siz[id]&&siz[v]>maxn){
				maxn=siz[v];
				g[id]=g[v];
				while(g[id]!=id){
					if((siz[g[id]]<<1)>=siz[id])break;
					g[id]=f[g[id]];
				}
			}
		}
	if(!maxn)g[id]=id;
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",f+i);
		addEdge(i,f[i]);
		addEdge(f[i],i);
	}
	dp(1);
	while(q--){
		int u; scanf("%d",&u);
		printf("%d\n",g[u]);
	}
	return 0;
}
