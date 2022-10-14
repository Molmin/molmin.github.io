// 2022.07.27

#include<bits/stdc++.h>
using namespace std;

int n,k,h[5001],dp[5001];

inline double K(int x,int y){
	return (h[y]-h[x])*1.0/(y-x);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",h+i);
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=0x3f3f3f3f;
		double mink=1145141919;
		for(int j=i-1;j>=max(i-k,1);j--){
			if(K(j,i)<=mink)dp[i]=min(dp[j]+1,dp[i]);
			mink=min(mink,K(j,i));
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
