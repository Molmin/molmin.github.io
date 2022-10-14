#include<bits/stdc++.h>
using namespace std;

struct student{
    string name;
    int score;
    bool operator<(student tmp)const{
        if(score==tmp.score)return name<tmp.name;
        return score>tmp.score;
    }
}s[1000];

int cnt;
struct Student{
    string name;
    vector<pair<int,double> > exams;
    double score[4],sum;
    bool operator<(Student tmp)const{
        return sum>tmp.sum;
    }
}stu[5000];

void newstudent(string name,int id,int t,double score,double value,double preval){
    int i=0;
    while(i<=cnt&&stu[i].name!=name)i++;
    if(i==cnt+1){
        stu[++cnt].name=name;
        stu[cnt].exams.clear();
        for(int i=0;i<4;i++)
            stu[cnt].score[i]=0;
        stu[cnt].sum=0;
    }
    // for(int j=1;j<=)
    stu[i].exams.push_back({id,score});
    if(t==-1){
        for(int j=0;j<4;j++)
            stu[i].score[j]=stu[i].score[j]*preval+score*value;
    }
    stu[i].score[t]=stu[i].score[t]*preval+score*value;
}

int main(){
    freopen("tmp.txt","r",stdin);
    freopen("data.txt","w",stdout);
    int id=0;
    while(true){
        string examname;
        getline(cin,examname);
        if(examname=="end")break;
        int fullscore,type;
        scanf("%d%d",&fullscore,&type);
        int a,b; scanf("%d%d",&a,&b);
        double value=a*1.0/b;
        scanf("%d%d",&a,&b);
        double preval=a*1.0/b;
        cout<<examname<<"|"<<fullscore<<"|"<<type;
        int i=0;
        while(true){
            cin>>s[i].name;
            if(s[i].name=="end")break;
            scanf("%d",&s[i].score);
            i++;
        }
        sort(s,s+i);
        for(int j=0;j<i;j++){
            cout<<";"<<s[j].name<<":"<<s[j].score;
            newstudent(s[j].name,id,type,s[j].score*100.0/s[0].score,value,preval);
        }
        printf("\n");
        id++;
        getline(cin,examname);
    }
    for(int i=1;i<=cnt;i++){
        stu[i].sum=0;
        for(int j=0;j<4;j++)
            stu[i].sum+=stu[i].score[j];
    }
    sort(stu+1,stu+1+cnt);
    for(int i=1;i<=cnt;i++){
        cout<<"\n"<<stu[i].name<<"?";
        for(int j=0;j<4;j++)
            printf("%.3lf;",stu[i].score[j]);
        printf("%.3lf|",stu[i].sum);
        bool flag=false;
        for(pair<int,double> j:stu[i].exams){
            if(flag)printf(";");
            flag=true;
            printf("%d,%.1lf",j.first,j.second);
        }
    }
    return 0;
}