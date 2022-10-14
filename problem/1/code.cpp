// 2022.06.30

#include<bits/stdc++.h>
using namespace std;

int T,n;

inline bool prime(int x){
    if(x<2)return false;
    int t=sqrt(x);
    for(int i=2;i<=t;i++)
        if(x%i==0)return false;
    return true;
}

long long Gcd(long long x,long long y){
    if(y==0)return x;
    return Gcd(y,x%y);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int u=n+1,v=n;
        while(!prime(u))u++;
        while(!prime(v))v--;
        long long ans1=n-u-v+1,ans2=(long long)u*v;
        ans1*=2,ans2<<=1,ans1=ans2/2+ans1;
        long long gcd=Gcd(ans1,ans2);
        printf("%lld/%lld\n",ans1/gcd,ans2/gcd);
    }
    return 0;
}
