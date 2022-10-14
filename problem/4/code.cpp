// 2022.07.01

#include<bits/stdc++.h>
using namespace std;

int n,m;
map<long long,long long> s[21];
long long k,tot,now,a[21][21];

void dfs1(int x,int y){
	if(x+y==(n+m)/2+1){
		s[x][k^now^a[x][y]]++;
		return;
	}
	now^=a[x][y];
	if(x<n)dfs1(x+1,y);
	if(y<m)dfs1(x,y+1);
	now^=a[x][y];
}

void dfs2(int x,int y){
	if(x+y==(n+m)/2+1){
		tot+=s[x][now];
		return;
	}
	now^=a[x][y];
	if(x)dfs2(x-1,y);
	if(y)dfs2(x,y-1);
	now^=a[x][y];
}

int main(){
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",a[i]+j);
	dfs1(1,1);
	now=0;
	dfs2(n,m);
	printf("%lld\n",tot);
	return 0;
}
