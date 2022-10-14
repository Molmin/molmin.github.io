// 2022.07.03

#include<bits/stdc++.h>
using namespace std;

struct point{
    double x,y;
    bool operator<(point tmp)const{
        return x==tmp.x?y<tmp.y:x<tmp.x;
    }
}a[100001];
double dis(point x,point y){
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
double slope(point x,point y){
    return (y.y-x.y)/(y.x-x.x);
}

int n,m;

vector<point> ans1,ans2;

pair<point,point> find1(point t){
    int l=0,r=ans1.size()-2;
    while(l<r){
        int mid=l+r+1>>1;
        if(t.x<ans1[mid].x)r=mid-1;
        else l=mid;
    }
    return{ans1[l],ans1[l+1]};
}

pair<point,point> find2(point t){
    int l=0,r=ans2.size()-2;
    while(l<r){
        int mid=l+r+1>>1;
        if(t.x<ans2[mid].x)r=mid-1;
        else l=mid;
    }
    return{ans2[l],ans2[l+1]};
}

int main(){
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        double y=1,y_=2;
        while(y<=y_&&ans1.size()>=2){
            point p1=ans1[ans1.size()-2],
                  p2=ans1[ans1.size()-1];
            y=slope(p1,p2),
            y_=slope(p1,a[i]);
            if(y<=y_)ans1.pop_back();
        }
        ans1.push_back(a[i]);
    }
    for(int i=1;i<=n;i++){
        double y=2,y_=1;
        while(y>=y_&&ans2.size()>=2){
            point p1=ans2[ans2.size()-2],
                  p2=ans2[ans2.size()-1];
            y=slope(p1,p2),
            y_=slope(p1,a[i]);
            if(y>=y_)ans2.pop_back();
        }
        ans2.push_back(a[i]);
    }
    scanf("%d",&m);
    int tot=0;
    for(int i=1;i<=m;i++){
        point tmp;
        scanf("%lf%lf",&tmp.x,&tmp.y);
        point p1=ans1[0],p2=ans1[ans1.size()-1];
        if(tmp.x<p1.x||tmp.x>p2.x)continue;
        double k=slope(p1,tmp),k1=slope(p1,p2);
        if(k==k1){tot++;continue;}
        pair<point,point> ret;
        if(k<k1)ret=find2(tmp);
        else ret=find1(tmp);
        double k2=slope(ret.first,tmp),
               k3=slope(ret.first,ret.second);
        if(k2==k3||int(k<k1)+int(k2<k3)==1)tot++;
    }
    printf("%d\n",tot);
    return 0;
}
