// 2022.07.04

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n,a[100][4],t[100];

struct Node{
    // 状态结构体
    ull value;
    double p;
    int nxt;
}node[5000000];
int head[5000000],cnt; // 对状态模 5e6 的余数使用链式前向星存储

inline ull gethash(){
    // 计算当前状态的哈希值
    for(int i=1;i<=n;i++){
        t[i]=0;
        if(i!=n&&(!a[i][2]||(!a[i][1]&&!a[i][3])))continue; // 遇到无效层
        bool flag=false;
        if(a[i][1]>a[i][3])
            swap(a[i][1],a[i][3]),flag=true; // 等价交换
        for(int j=1;j<=3;j++)
            t[i]|=a[i][j]<<(j-1<<1); // 状态压缩计算
        if(flag)swap(a[i][1],a[i][3]); // 换回去
    }
    sort(t+1,t+n); // 对除了顶层的状态压缩值进行排序
    ull tmp=0;
    for(int i=1;i<=n;i++)
        if(t[i])tmp<<=6,tmp|=t[i]; // 计算最终哈希值
    return tmp;
}
inline int getid(ull val){
    int headid=val%5000000;
    for(int i=head[headid];i;i=node[i].nxt)
        if(node[i].value==val)return i; // 找到该状态，返回 id
    // 没有找到该状态，将状态加入列表中
    node[++cnt]={val,-1,head[headid]};
    head[headid]=cnt;
    return cnt;
}

double dfs(ull now){
    int id=getid(now);
    if(node[id].p>=0)return node[id].p;
    double error=1/6.0,sum=0;
    for(int color=1;color<=3;color++){ // 枚举颜色
        double p=1.0/(color==1?6:3),minn=1e10;
        // p: 该颜色权重，即出现概率
        for(int i=1;i<n;i++)
            for(int j=1;j<=3;j++){
                if(a[i][j]!=color)continue;
                if(j==2&&(!a[i][1]||!a[i][3]))continue; // 删除后塔不符合条件，故退出
                if(j!=2&&!a[i][2])continue; // 删除后塔不符合条件，故退出
                a[i][j]=0;
                bool flag=false;
                if(a[n][1]&&a[n][2]&&a[n][3])n++,flag=true; // 需要新建一层
                for(int k=1;k<=3;k++){
                    if(a[n][k])continue;
                    a[n][k]=color;
                    minn=min(minn,dfs(gethash())+1.0); // 更新最小期望
                    a[n][k]=0;
                }
                // 将之前修改的状态恢复
                if(flag)n--;
                a[i][j]=color;
            }
        if(minn>1e9)error+=p; // 不存在合法操作
        else sum+=p*minn; // 统计期望
    }
    if(error>0.99)return node[id].p=0; // 游戏结束
    else return node[id].p=(sum+error*1.0)/(1-error); // 统计期望
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            char ch;
            scanf(" %c",&ch);
            if(ch=='R')a[i][j]=1;
            if(ch=='G')a[i][j]=2;
            if(ch=='B')a[i][j]=3;
        }
        if(a[i][1]>a[i][3])swap(a[i][1],a[i][3]); // 等价交换
    }
    printf("%.4lf\n",dfs(gethash()));
    return 0;
}
