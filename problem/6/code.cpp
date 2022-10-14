// 2022.07.03

#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
    void read(){
        scanf("%d%d",&x,&y);
    }
    void add(int addx,int addy){
        x+=addx,y+=addy;
    }
};
struct Rectangle{
    point l,r;
    void read(){
        l.read(); r.read();
    }
    void add(int x,int y){
        l.add(x,y); r.add(x,y);
    }
    long long area(){
        if(l.x>=r.x)return 0;
        if(l.y>=r.y)return 0;
        return (long long)(r.x-l.x)*(r.y-l.y);
    }
};
long long calcrossarea(Rectangle a,Rectangle b){
    Rectangle tmp;
    tmp.l.x=max(a.l.x,b.l.x);
    tmp.l.y=max(a.l.y,b.l.y);
    tmp.r.x=min(a.r.x,b.r.x);
    tmp.r.y=min(a.r.y,b.r.y);
    return tmp.area();
}
struct Frame{
    Rectangle out,in;
    void read(){
        out.read(); in.read();
    }
    void add(int x,int y){
        out.add(x,y); in.add(x,y);
    }
    vector<int> getxmaybe(){
        return{out.l.x,in.l.x,in.r.x,out.r.x};
    }
    vector<int> getymaybe(){
        return{out.l.y,in.l.y,in.r.y,out.r.y};
    }
}a,b;
long long calarea(Frame a,Frame b){
    return calcrossarea(a.out,b.out)+calcrossarea(a.in,b.in)-
           calcrossarea(a.out,b.in)-calcrossarea(a.in,b.out);
}

int main(){
	freopen("frames.in","r",stdin);
	freopen("frames.out","w",stdout);
    a.read(); b.read();
    vector<int> aX=a.getxmaybe(),aY=a.getymaybe(),
                bX=b.getxmaybe(),bY=b.getymaybe();
    long long answer=0;
    for(int ax:aX)for(int ay:aY)
        for(int bx:bX)for(int by:bY){
            Frame tmp=a; tmp.add(bx-ax,by-ay);
            answer=max(answer,calarea(tmp,b));
        }
    printf("%lld\n",answer);
    return 0;
}
