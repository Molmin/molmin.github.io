// 2022.06.01

#include<bits/stdc++.h>
using namespace std;

void error(){
    //由于此代码用到的地方较多，故封装成一个函数
	printf("-1\n"); exit(0);
}

int n=10000,m;

struct Edge{
	int to,nxt;
}edge[20003];
int head[10001],cntEdge;
inline void addEdge(int u,int v){
	edge[++cntEdge]={v,head[u]},head[u]=cntEdge;
}

int deg[10001]; // 每个点的度

int blockid[10001],blockcnt,blockf[10001];
/* blockid 表示点所在的连通块编号
   blockcnt 表示连通块数目
   blockf 表示点所在连通块中编号最小的点 */
void dfs_block(int id,int block){
	blockid[id]=block;
	for(int i=head[id];i;i=edge[i].nxt)
		if(blockid[edge[i].to]==0&&deg[edge[i].to])
			dfs_block(edge[i].to,block);
}

bool used[10001]; // 这个边输出答案时是否被使用过，可以避免重边情况
int findedge(int u,int v){
    // 找到 u 和 v 之间的边
	for(int i=head[u];i;i=edge[i].nxt)
		if(edge[i].to==v&&!used[i+1>>1])return i;
	return -1;
}

bool vis[10002];
void dfs(int id,vector<int> &tmp){
    // 找欧拉路径，答案存储在 tmp 里
	if(deg[id]==0){
        // 这个点已经没有出边
		tmp.push_back(id); return;
	}
	for(int i=head[id];i;i=edge[i].nxt){
		if(vis[i+1>>1])continue;
		vis[i+1>>1]=true; // 标记走过的边
		deg[edge[i].to]--,deg[id]--;
		dfs(edge[i].to,tmp);
	}
	tmp.push_back(id);
}

void print(vector<int> answer,int l,int r){
	for(int i=l;i<=r;i++){
		int tmp=findedge(answer[i],answer[i+1])+1>>1;
		printf("%d ",tmp),used[tmp]=true;
	}
	printf("\n");
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&m);
	if(m==1)error();
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		deg[u]++,deg[v]++;
		addEdge(u,v); addEdge(v,u);
	}
	vector<int>oddid;
	for(int i=1;i<=n;i++){
		if(deg[i]&&blockid[i]==0)
			blockf[blockcnt+1]=i,
			dfs_block(i,++blockcnt);
		if(deg[i]&1)oddid.push_back(i); // 找到一个奇点
	}
	if(blockcnt>2)error(); // 连通块数量超过 2，无解
	if(blockcnt==1){
		if(oddid.size()==4){
			bool flag=false; int t1=0,t2=0;
            // 找没有连边的两个奇点
			for(int i=0;i<4&&!flag;i++)
				for(int j=i+1;j<4&&!flag;j++)
					if(findedge(oddid[i],oddid[j])==-1){
						swap(oddid[0],oddid[i]);
						swap(oddid[1],oddid[j]);
						flag=true;
					}
            // 连边
			addEdge(oddid[0],oddid[1]);
			addEdge(oddid[1],oddid[0]);
			deg[oddid[0]]++,deg[oddid[1]]++;
			vector<int>tmp;
			dfs(oddid[2],tmp);
			int t=0;
            // 找到临时添加的边
			while((tmp[t]!=oddid[0]||tmp[t+1]!=oddid[1])&&
				(tmp[t]!=oddid[1]||tmp[t+1]!=oddid[0]))t++;
			printf("%d\n",t);
			print(tmp,0,t-1);
			printf("%d\n",m-t);
			print(tmp,t+1,tmp.size()-2);
		}
		else{
			vector<int>tmp;
            // 找一条路径遍历整个图
			if(oddid.size()==0)
				dfs(blockf[1],tmp);
			else if(oddid.size()==2)
				dfs(oddid[0],tmp);
			else error();
            // 断开第一条边输出
			printf("1\n");
			print(tmp,0,0);
			printf("%d\n",tmp.size()-2);
			print(tmp,1,tmp.size()-2);
		}
	}
	if(blockcnt==2){
        // 有两个连通块时，分别找路径
		vector<int>odd1,odd2;
		for(int i:oddid)
			if(blockid[i]==1)odd1.push_back(i);
			else odd2.push_back(i);
		if(odd1.size()!=0&&odd1.size()!=2)error();
		if(odd2.size()!=0&&odd2.size()!=2)error();
		vector<int>ans1,ans2;
		if(odd1.size()==0){
			int t=1;
			while(blockid[t]!=1)t++; 
			dfs(t,ans1);
		}
		else dfs(odd1[0],ans1);
		printf("%d\n",ans1.size()-1);
		print(ans1,0,ans1.size()-2);
		if(odd2.size()==0){
			int t2=1;
			while(blockid[t2]!=2)t2++; 
			dfs(t2,ans2);
		}
		else dfs(odd2[0],ans2);
		printf("%d\n",ans2.size()-1);
		print(ans2,0,ans2.size()-2);
	}
	return 0;
} 
