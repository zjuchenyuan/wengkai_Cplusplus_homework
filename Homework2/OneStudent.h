#ifndef __ONESTUDENT_H
#define __ONESTUDENT_H
#include <string>
#include <vector>
#include <map> 
using namespace std;
class OneStudent{/*Only One Student in a class, maybe using map<stuname, map<string,int> > is a much better choice*/
private:
    string stuname;
    map<string,int> stuscore;
public:
    inline void inputname(string& iname){stuname=iname;};
    inline string& getname(){return stuname;}
    inline void inputonescore(string& iclassname,int iscore){
        stuscore[iclassname]=iscore;
    };
    inline int getscore(string& iclassname){
        map<string,int>::iterator i=stuscore.find(iclassname);
        if(i==stuscore.end()) return -1;
        else return i->second;
    };
    inline int getmin(){
        map<string,int>::iterator i;
        int min=stuscore.begin()->second;
        for(i=stuscore.begin();i!=stuscore.end();i++){
            if(i->second<min) min=i->second;
        } 
        return min;
    }
    inline int getmax(){
        map<string,int>::iterator i;
        int max=stuscore.begin()->second;
        for(i=stuscore.begin();i!=stuscore.end();i++){
            if(i->second>max) max=i->second;
        } 
        return max;
    }
    double getaverage();
};

#endif
