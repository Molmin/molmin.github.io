// 2022.07.26

#include<bits/stdc++.h>
using namespace std;

int n,k;

struct Edge{
	int to,w,nxt;
}edge[4001];
int cntEdge,head[2001];
inline void addEdge(int u,int v,int w){
	edge[++cntEdge]={v,w,head[u]},head[u]=cntEdge;
}

int siz[2001];
long long dp[2001][2001];
void dfs(int id,int father){
	siz[id]=1,dp[id][0]=dp[id][1]=0;
	for(int i=head[id];i;i=edge[i].nxt)
		if(edge[i].to!=father){
			int v=edge[i].to;
			dfs(v,id); siz[id]+=siz[v];
			for(int x=min(k,siz[id]);x>=0;x--)
				for(int y=0;y<=min(x,siz[v]);y++)
					if(dp[id][x-y]!=-1)dp[id][x]=max(dp[id][x],dp[id][x-y]+dp[v][y]+
						(long long)edge[i].w*(y*(k-y)+(siz[v]-y)*(n-k-(siz[v]-y))));
		}
}

int main(){
	memset(dp,-1,sizeof dp);
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	dfs(1,0);
	printf("%lld\n",dp[1][k]);
	return 0;
}
