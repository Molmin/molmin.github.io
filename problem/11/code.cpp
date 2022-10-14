// 2022.07.24

#include<bits/stdc++.h>
using namespace std;

namespace solve{
	int n,a[200001];
	void main(){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		int now=1,answer=0;
		for(int i=1;i<=n;i++){
			while(now<=n&&a[now]==a[i])now++;
			if(now==n+1){
				answer=max(answer,now-i);
				break;
			}
			int pre=n,tot=1;
			while(now<=pre){
				int l=now-1,r=pre-1;
				while(l<r){
					int mid=l+r+1>>1;
					if(a[mid]*2<=(a[i]+a[pre]))l=mid;
					else r=mid-1;
				}
				pre=l;
				if(pre<now)break;
				tot++;
			}
			answer=max(answer,tot+now-i);
		}
		printf("%d\n",n-answer);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--)
		solve::main();
	return 0;
}
