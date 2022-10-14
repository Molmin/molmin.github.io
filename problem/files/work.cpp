#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("config.txt","w",stdout);
    int n;
    scanf("%d",&n);
    string name;
    getline(cin,name);
    printf("Files;114514 s;1919810 TB;8\n基础算法\n本地题/模拟赛题/原创题\n\n");
    for(int i=1;i<=n;i++){
        getline(cin,name);
        if(i>1)printf("|||");
        cout<<"https://molmin.github.io/problem/files/"<<name<<"||"<<name;
    }
    return 0;
}