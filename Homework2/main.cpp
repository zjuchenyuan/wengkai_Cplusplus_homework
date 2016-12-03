#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "OneStudent.h"
#include "Classes.h"
using namespace std;
string input(){
	string tmp;
	cin>>tmp;
	return tmp;
}
int main(){
	vector<OneStudent> students;
	Classes classes;
	string stuname,classname;int score;
	cout<<"STUDENT NAME:";
	while((stuname=input())!="end"){
		OneStudent somebody;
		somebody.inputname(stuname);
		cout<<"Input Classname:";
		while((classname=input())!="end"){
			if(somebody.getscore(classname)!=-1) cout<<"ERROR: duplicate classname!";
			else{
				cout<<"Input His Score of "<<classname<<":";
				cin>>score;
				somebody.inputonescore(classname,score);
				classes.inputOneScore(classname,score);
			}
			cout<<"Input Classname:";
		}
		students.push_back(somebody);
		cout<<"STUDENT NAME:";
	}
	cout<<"----All Students input finished----"<<endl;
	cout<<"=======STUDENTS STATISTICS========="<<endl;
	vector<OneStudent>::iterator i;
	for(i=students.begin();i!=students.end();i++){
		cout<<i->getname()<<" Average: "<<i->getaverage()<<"; Min: "<<i->getmin()<<";Max: "<<i->getmax()<<endl;
	}
	classes.printSummary();
}

/*int testClasses(){
	Classes haha;
	string tmp="C++";
	haha.inputOneScore(tmp,60);haha.inputOneScore(tmp,70);
	cout<<haha.getAverage(tmp)<<endl;
	tmp="English";
	haha.inputOneScore(tmp,99);
	cout<<haha.size();
}
int testOneStudnet(){
	cout<<"hi"<<endl;
	OneStudent me;
	string myname="chenyuan";
	string classname="C++";
	me.inputname(myname);
	cout<<me.getname()<<endl;
	me.inputonescore(myname,99);
	me.inputonescore(classname,96); 
	cout<<me.getscore(classname)<<endl<<me.getscore(myname)<<endl;
	cout<<me.getaverage();
}*/
/*
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
}*/
