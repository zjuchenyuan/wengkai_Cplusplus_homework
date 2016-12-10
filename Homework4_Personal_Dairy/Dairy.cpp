#include <string>
#include <iostream>
#include <map> 
#include <fstream>
#include <sstream>
#include <ctime>
#include "Dairy.h"
using namespace std;
int Dairy::today() {
        char buf[128];
        int thedate;
        time_t lt;
        time(&lt);
        strftime( buf, 128, "%Y%m%d", localtime(&lt));
        stringstream s;
        s<<buf;
        s>>thedate;
        return thedate;
}
Dairy::Dairy(string filename):fn(filename){
        ifstream fp;
        fp.open(filename.c_str(),ios::in);
        if(!fp.is_open()) return;
        string d,content;int date;
        while(!fp.eof()){
            content="";
            date=0;
            fp>>date;
            if(date==0) break;
            getline(fp,d);//discard the '\n'
            getline(fp,d);
            do{
                content+=d+"\n";
                getline(fp,d);
            }while(d!="."&&!fp.eof());
            content.erase(content.size()-1);//discard the '\n'
            data[date]=content;
        }
}
Dairy::~Dairy(){
        ofstream fp;
        fp.open(fn.c_str(),ios_base::out);
        if(!fp.is_open()) {
            cout<<"ERROR: Cannot save file!"<<endl;
            cout<<"To avoid losting data, here is the Dairy:"<<endl;
            pdlist(0,99999999,false);
            return;
        }
        for(map<int,string>::iterator i=data.begin();i!=data.end();i++){
                fp<<i->first<<endl<<i->second<<endl<<"."<<endl;
        }
};
void Dairy::pdlist(int begin,int end,bool friendly){
        map<int,string>::iterator i;
        int count=0; 
        //cout<<"======="<<endl;
        for(i=data.begin();i!=data.end();i++){
            if(i->first>=begin&&i->first<=end)
                if(friendly) cout<<"Date:"<<i->first<<endl<<"Content:\n"<<i->second<<endl<<"======="<<endl;
                else cout<<i->first<<endl<<i->second<<endl<<"."<<endl;
                count++;
        }
        if(count==0) cout<<"No Content!";
}

