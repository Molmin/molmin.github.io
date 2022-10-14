// 2022.05.18

#include<bits/stdc++.h>
using namespace std;
inline int Gcd(int x,int y){
    if(y==0)return x;
    else return Gcd(y,x%y);
}
int n,s[100001];
struct node{
    int gcd,minval,mintot;
    inline node operator+(node x)const{
        // 合并两段数的信息 
        node tmp; tmp.mintot=0;
        // 求出区间最大公因数和最小值
        tmp.gcd=Gcd(gcd,x.gcd);
        tmp.minval=min(minval,x.minval);
        // 若区间最小值等于最终最小值，就把数量加入总区间最小值个数
        if(tmp.minval==minval)tmp.mintot+=mintot;
        if(tmp.minval==x.minval)tmp.mintot+=x.mintot;
        return tmp;
    }
}tree[400001];
void work(int id,int l,int r){
    if(l==r){
        tree[id]={s[l],s[l],1};
        return;
    }
    int mid=l+r>>1;
    work(id<<1,l,mid); work((id<<1)+1,mid+1,r);
    // 合并区间
    tree[id]=tree[id<<1]+tree[(id<<1)+1];
}
node query(int id,int L,int R,int l,int r){
    if(l==L&&r==R)return tree[id];
    int mid=L+R>>1;
    if(l<=mid&&r<=mid)return query(id<<1,L,mid,l,r);
    if(l>mid&&r>mid)return query((id<<1)+1,mid+1,R,l,r);
    return query(id<<1,L,mid,l,mid)+query((id<<1)+1,mid+1,R,mid+1,r);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",s+i);
    work(1,1,n);
    int t; scanf("%d",&t);
    while(t--){
        int l,r; scanf("%d%d",&l,&r);
        node tmp=query(1,1,n,l,r);
        if(tmp.gcd!=tmp.minval)printf("%d\n",r-l+1);
        else printf("%d\n",r-l+1-tmp.mintot);
    }
    return 0;
}
