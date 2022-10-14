// 2022.07.26

#include<bits/stdc++.h>
using namespace std;

int n,a[1000001];
bool notroot[1000001];

struct Edge{
	int to,nxt;
}edge[2000001];
int head[1000001],cntEdge;
inline void addEdge(int u,int v){
	edge[++cntEdge]={v,head[u]},head[u]=cntEdge;
}

int U,V,E; bool vis[1000001];
void findCircle(int id,int father){
	vis[id]=true;
	for(int i=head[id];i;i=edge[i].nxt){
		int to=edge[i].to;
		if(father==to)continue;
		if(vis[to]){
			U=id,V=to,E=i;
			continue; // 由于还需要标记剩下点是否 vis，故不能直接退出 
		}
		findCircle(to,id);
	}
}

long long dp[1000001][2];
// dp[id][0]: 在以 id 为根的子树内，id 被选中，子树中独立集的最大大小 
// dp[id][1]: 在以 id 为根的子树内，id 不被选中，子树中独立集的最大大小 
void dfs(int id,int father){
	dp[id][0]=a[id],dp[id][1]=0;
	for(int i=head[id];i;i=edge[i].nxt){
		if(i==E||(i-1^1)+1==E)continue;
		int to=edge[i].to;
		if(to==father)continue;
		dfs(to,id);
		dp[id][0]+=dp[to][1];
		dp[id][1]+=max(dp[to][0],dp[to][1]);
	} 
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d%d",a+i,&x);
		addEdge(i,x);
		addEdge(x,i); 
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		findCircle(i,0);
		dfs(U,0);
		long long ans1=dp[U][1];
		dfs(V,0);
		long long ans2=dp[V][1];
		sum+=max(ans1,ans2);
	}
	printf("%lld\n",sum);
	return 0;
}
