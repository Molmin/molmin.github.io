// 2022.06.17

#include<bits/stdc++.h>
using namespace std;

int n,m,k;

struct Edge{
    int to,nxt;
}edge[200001];
int head[100001],cntEdge;
inline void addEdge(int u,int v){
    edge[++cntEdge]={v,head[u]},head[u]=cntEdge;
}

int dfn[100001],viscnt,vislist[100001];
bool vis[100001];

void dfs(int id){
    vis[id]=true,dfn[id]=++viscnt,
    vislist[viscnt]=id; // 记录 dfn 为 viscnt 的点为 id
    for(int i=head[id];i;i=edge[i].nxt)
        if(!vis[edge[i].to]){
            dfs(edge[i].to); break;
        }
        else if(dfn[edge[i].to]+k<=dfn[id]){
            // 找到环
            printf("%d\n",dfn[id]-dfn[edge[i].to]+1);
            for(int j=dfn[edge[i].to];j<=dfn[id];j++)
                printf("%d ",vislist[j]);
            printf("\n"); exit(0);
        }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1);
    return 0;
}
