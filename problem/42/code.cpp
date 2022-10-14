// 2022.09.30

#include<bits/stdc++.h>
using namespace std;
const long double one=(long double)1.0;

inline bool check(long long b,long long y,long long l){
    if(b<10)return false;
    long long to=0,mul=1;
    while(y){
        if(y%b>9)return false;
        to+=mul*(y%b);
        y/=b;
        mul*=10;
    }
    return to>=l;
}

int main(){
    freopen("age.in","r",stdin);
    freopen("age.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        long long y,l,answer=10;
        scanf("%lld%lld",&y,&l);
        for(long long i=l;i<=99;i++){
            int a0=i%10,a1=i/10;
            // 枚举转换后的结果,则 a1*b+a0=y
            long long b=(y-a0)/a1;
            if(check(b,y,l))answer=max(answer,b);
        }
        for(long long i=max(100ll,l);i<=999;i++){
            long double a0=i%10-y,a1=i/10%10,a2=i/100;
            // 枚举转换后的结果,则 a2*b^2+a1*b+a0=y
            long double delta=sqrt(a1*a1-4*one*a0*a2);
            long double b0=(-a1+delta)/(2*one*a2),
                        b1=(-a1-delta)/(2*one*a2);
            if(check((long long)b0,y,l))answer=max(answer,(long long)b1);
            if(check((long long)b0,y,l))answer=max(answer,(long long)b0);
        }
        for(long long b=1000000;b>answer;b--)
            if(check(b,y,l))answer=b;
        printf("%lld\n",answer);
    }
    return 0;
}
