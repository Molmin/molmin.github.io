// 2022.08.10

#include<bits/stdc++.h>
using namespace std;

int n,root,son[501];

struct Edge{
	int to,nxt;
}edge[501];
int head[501],cntEdge;
inline void addEdge(int u,int v){
	edge[++cntEdge]={v,head[u]},head[u]=cntEdge;
}

bool ok[501][501][2];
/* ok[i][j][0/1] 表示以 i 为根的子树中任意一条链黑点个数都为 j，
   且 i 节点为 红/黑 时候是否可行 */

bool color[501];
void getcolor(int id,int len,bool p){
	color[id]=p;
	if(son[id]==0)return;
	if(son[id]==1){
		getcolor(edge[head[id]].to,0,false);
		return;
	}
	for(int i=head[id];i;i=edge[i].nxt){
		int to=edge[i].to;
		if(p)getcolor(to,len-1,ok[to][len-1][1]);
		else getcolor(to,len,true);
	}
}

void dp(int id){
	if(son[id]==0){
		ok[id][0][0]=ok[id][1][1]=true;
		return;
	}
	if(son[id]==1){
		int to=edge[head[id]].to;
		dp(to);
		ok[id][1][1]=ok[to][0][0];
		return;
	}
	for(int j=0;j<=n;j++)
		ok[id][j][0]=ok[id][j][1]=true;
	for(int i=head[id];i;i=edge[i].nxt){
		int to=edge[i].to;
		dp(to);
		for(int j=0;j<=n;j++){
			ok[id][j][0]&=ok[to][j][1];
			if(j)ok[id][j][1]&=ok[to][j-1][0]|ok[to][j-1][1];
		}
	}
	ok[id][0][1]=false;
}

int main(){
    freopen("rbt.in", "r", stdin);
    freopen("rbt.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int p;
		scanf("%d",&p);
		if(p)addEdge(p,i),son[p]++;
		else root=i;
	}
	dp(root);
	int i=0;
	while(i<=n&&!ok[root][i][0]&&!ok[root][i][1])i++;
	if(ok[root][i][0]||ok[root][i][1]){
		getcolor(root,i,ok[root][i][1]);
		for(int i=1;i<=n;i++)
			if(color[i])printf("B");
			else printf("R");
	}
	else printf("Impossible\n");
	return 0;
}
