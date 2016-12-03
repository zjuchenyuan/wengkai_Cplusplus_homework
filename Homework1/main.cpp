#include <iostream>
#include <string>
#include "Record.h"
#include "Students.h"
int main(){
    int len,rlen,i,j,tmp;
    string name;
    cout<<"How many Students? Your input: 10"<<endl;
    len=10;
    cout<<"How many courses in each record? Your input: 3"<<endl;
    rlen=3;
    Students s(len,rlen);
    for(i=1;i<=len;i++){
        cout<<"[Student "<<i<<"] Name:";
        cin>>name;
        s.inputRecordName(i,name);
        for(j=1;j<=rlen;j++){
            cout<<"[Student "<<i<<"] [Course "<<i<<"] Score:";
            cin>>tmp;
            s.inputRecordScore(i,j,tmp);
        }
    }
    cout<<"------------------"<<endl;
    cout<<"no\tname\tscore1\tscore2\tscore3\taverage"<<endl;
    for(i=1;i<=len;i++){
        cout<<i<<"\t"<<s.getRecordName(i)<<"\t";
        for(j=1;j<=rlen;j++) cout<<s.getRecordScore(i,j)<<"\t";
        cout<<s.getRecordAverage(i)<<endl;
    }
    cout<<"\taverage\t";
    for(j=1;j<=rlen;j++) cout<<s.getScoreAverage(j)<<"\t";
    cout<<endl;
    cout<<"\tmin\t";
    for(j=1;j<=rlen;j++) cout<<s.getScoreMin(j)<<"\t";
    cout<<endl;
    cout<<"\tmax\t";
    for(j=1;j<=rlen;j++) cout<<s.getScoreMax(j)<<"\t";
    cout<<endl;
}