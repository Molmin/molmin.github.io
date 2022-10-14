// 2022.07.26

#include<bits/stdc++.h>
using namespace std;

int n;

struct Edge{
	int to,nxt;
}edge[3001];
int head[1501],cntEdge;
inline void addEdge(int u,int v){
	edge[++cntEdge]={v,head[u]},head[u]=cntEdge;
}

int dp[1501][2];
// dp[id][0]: 在以 id 为根的子树内，id 被选中，子树中点覆盖集合的最小个数 
// dp[id][1]: 在以 id 为根的子树内，id 不被选中，子树中点覆盖集合的最小个数 
void dfs(int id,int father){
	dp[id][0]=1;
	for(int i=head[id];i;i=edge[i].nxt){
		int to=edge[i].to;
		if(to==father)continue;
		dfs(to,id);
		dp[id][0]+=min(dp[to][0],dp[to][1]);
		dp[id][1]+=dp[to][0];
	} 
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int id,k,x;
		scanf("%d%d",&id,&k),id++;
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			addEdge(id,x+1);
			addEdge(x+1,id);
		}
	}
	dfs(1,0);
	printf("%d\n",min(dp[1][0],dp[1][1]));
	return 0;
}
