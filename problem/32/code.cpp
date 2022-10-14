// 2022.08.13

#include<bits/stdc++.h>
using namespace std;

int k,cnt;
bool mp[100][100];

int main(){
	scanf("%d",&k);
	for(int i=3;k>>(i/3-1);i+=3){
		mp[i][i+3]=mp[i][i+4]
		=mp[i+1][i+3]=mp[i+1][i+4]
		=mp[i+2][i+5]=true;
		cnt=i+5;
		if((k>>(i/3-1))&1)mp[i+1][i+2]=true;
	}
	mp[cnt][2]=mp[1][3]=mp[1][4]=true;
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++)
			if(mp[i][j]||mp[j][i])
				printf("Y");
			else printf("N");
		printf("\n");
	}
	return 0;
}
