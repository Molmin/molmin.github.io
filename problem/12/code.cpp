// 2022.07.25

#include<bits/stdc++.h>
using namespace std;

int n,m,nxt[100001];
struct Edge{
	int u,v,w;
}edge[400001];
int group[27]; // 组中的第一个点 

int f[100001];
inline int find(int id){
	if(f[id]!=id)f[id]=find(f[id]);
	return f[id];
}
inline void clear(){
	for(int i=1;i<=n;i++)f[i]=i;
}

inline bool haveline(int u,int v){
	for(int i=1;i<=m;i++){
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(fu==u&&fv==v)return true;
		if(fu==v&&fv==u)return true;
	}
	return false;
}

inline bool check(int W){
	clear();
	for(int i=1;i<=m;i++)
		if(W>=edge[i].w){
			int u=find(edge[i].u),v=find(edge[i].v);
			if(u!=v)f[u]=v;
		}
	bool flag=true,ok=true;
	for(int g=1;g<=26&&ok;g++){
		int u=0;
		for(int i=group[g];i&&ok;i=nxt[i]){
			int v=find(i);
			if(u==0)u=v;
			else if(u!=v){
				if(!flag)ok=false;
				else{
					if(haveline(u,v))f[v]=u,flag=false;
					else ok=false;
				}
			}
		}
	}
	return ok;
}

int main(){
	freopen("wifi.in","r",stdin);
	freopen("wifi.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch;
		scanf(" %c",&ch);
		int g=(ch=='#')?0:(ch-'a'+1);
		nxt[i]=group[g],group[g]=i;
	}
	int l=0,r=0;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w),
		edge[i].u++,edge[i].v++,r=max(r,edge[i].w);
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
