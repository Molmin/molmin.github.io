// 2022.08.15

#include<bits/stdc++.h> 
using namespace std;

int n,deg[1001];
bool p[1001];

struct Edge{
	int to,nxt;
}edge[2000];
int head[1001],cntEdge;
inline void addEdge(int u,int v){
	edge[++cntEdge]={v,head[u]},head[u]=cntEdge; 
	deg[u]++;
}

queue<int> Q;

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	for(int i=1;i<=n;i++)
		if(deg[i]==1)Q.push(i);
	for(int i=1;(i<<1)<=n;i++){
		int u=Q.front(); Q.pop();
		int v=Q.front(); Q.pop();
		printf("? %d %d\n",u,v);
		fflush(stdout);
		int lca;
		scanf("%d",&lca);
		if(lca==u||lca==v)
			return printf("! %d\n",lca),0;
		for(int j=head[u];j;j=edge[j].nxt){
			deg[edge[j].to]--;
			if(deg[edge[j].to]==1)
				Q.push(edge[j].to);
		}
		for(int j=head[v];j;j=edge[j].nxt){
			deg[edge[j].to]--;
			if(deg[edge[j].to]==1)
				Q.push(edge[j].to);
		}
		p[u]=p[v]=true;
	}
	for(int i=1;i<=n;i++)
		if(!p[i])return printf("! %d\n",i),0;
	return 0;
}
