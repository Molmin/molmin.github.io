// 2022.07.25

#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> Q; 

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	long long nowsum=0,answer=0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		while(!Q.empty()&&Q.top()>=a){
			int t=Q.top(); Q.pop();
			Q.push(t%a);
			nowsum+=t%a-t;
		}
		Q.push(a),nowsum+=a;
		answer+=nowsum;
	}
	printf("%lld\n",answer);
	return 0;
}
