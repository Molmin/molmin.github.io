// 2022.07.26

#include<bits/stdc++.h>
using namespace std;

int n,r[6001];
bool notroot[6001];

struct Edge{
	int to,nxt;
}edge[12001];
int head[6001],cntEdge;
inline void addEdge(int u,int v){
	edge[++cntEdge]={v,head[u]},head[u]=cntEdge;
}

int dp[6001][2];
// dp[id][0]: 在以 id 为根的子树内，id 被选中，子树中独立集的最大大小 
// dp[id][1]: 在以 id 为根的子树内，id 不被选中，子树中独立集的最大大小 
void dfs(int id,int father){
	dp[id][0]=r[id];
	for(int i=head[id];i;i=edge[i].nxt){
		int to=edge[i].to;
		if(to==father)continue;
		dfs(to,id);
		dp[id][0]+=dp[to][1];
		dp[id][1]+=max(dp[to][0],dp[to][1]);
	} 
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",r+i);
	for(int i=1;i<n;i++){
		int l,k;
		scanf("%d%d",&l,&k);
		addEdge(l,k);
		addEdge(k,l);
		notroot[l]=true;
	}
	int root=1;
	while(notroot[root])root++;
	dfs(root,0);
	printf("%d\n",max(dp[root][0],dp[root][1]));
	return 0;
}
