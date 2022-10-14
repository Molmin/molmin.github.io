// 2022.07.25

#include<bits/stdc++.h>
using namespace std;

int n,a[501],b[501];

int f[501][501],g[501];
int work(){
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	for(int i=1;i<=n;i++)f[i][i]=1;
	for(int l=2;l<=n;l++)
		for(int i=1,j=l;j<=n;i++,j++)
			if(b[i]==b[j])f[i][j]=f[i+1][j];
			else{
				f[i][j]=0x3f3f3f3f;
				for(int k=i;k<j;k++)
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			}
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
			g[i]=g[i-1];
			continue;
		}
		g[i]=0x3f3f3f3f;
		for(int j=1;j<=i;j++)
			g[i]=min(g[i],g[j-1]+f[j][i]);
	}
	return g[n];
}

int main(){
  freopen("necklace.in","r",stdin);
  freopen("necklace.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	int answer=work();
	for(int i=1,j=n;i<j;i++,j--)
		swap(a[i],a[j]);
	answer=min(answer,work());
	printf("%d\n",answer);
	return 0;
}
