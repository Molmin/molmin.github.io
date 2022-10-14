// 2022.07.26

#include<bits/stdc++.h>
using namespace std;

int n,m,f[301];

struct Edge{
	int to,nxt;
}edge[301];
int cntEdge,head[301];
inline void addEdge(int u,int v){
	edge[++cntEdge]={v,head[u]},head[u]=cntEdge;
}

int dp[301][301];
void dfs(int id){
	for(int i=head[id];i;i=edge[i].nxt){
		int v=edge[i].to; dfs(v);
		for(int j=m;j>=1;j--)
			for(int k=0;k<j;k++)
				dp[id][j]=max(dp[id][j],dp[id][j-k]+dp[v][k]);
	}
}

int main(){
	scanf("%d%d",&n,&m),m++;
	for(int i=1;i<=n;i++){
		scanf("%d%d",f+i,dp[i]+1);
		addEdge(f[i],i);
	}
	dfs(0);
	printf("%d\n",dp[0][m]);
	return 0;
}
