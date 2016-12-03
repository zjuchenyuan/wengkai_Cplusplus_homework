#include <iostream>
#include <string>
#include "Record.h"
#include "Students.h"

Students::Students(int ilen,int irlen):len(ilen),rlen(irlen){
        int i;
        data = new pRecord[ilen+1];
        for(i=1;i<=ilen;i++){
            data[i] = new Record(irlen);
        }
}
Students::~Students(){
        int i;
        for(i=1;i<=len;i++){
            delete data[i];
        }
        delete[] data;
}
int Students::get_rlen(){
        return rlen;
}
void Students::inputRecordName(int idx,string& name){
        data[idx]->inputname(name);
}
void Students::inputRecordScore(int idx,int rdx,int score){//inputRecordScore(2,1,4) means No.2 Studnets's score1=4
        data[idx]->inputscore(rdx,score);
}
int Students::getRecordScore(int idx,int rdx){
        return data[idx]->getscore(rdx);
}
double Students::getRecordAverage(int idx){
        return data[idx]->getaverage();
}
string& Students::getRecordName(int idx){
        return data[idx]->getname();
}
double Students::getScoreAverage(int rdx){
        int i,sum=0;
        for(i=1;i<=len;i++){
            sum += getRecordScore(i,rdx);
        }
        return (double)sum/len;
}
int Students::getScoreMin(int rdx){
        int min=9999,i;
        for(i=1;i<=len;i++){
            if(getRecordScore(i,rdx)<min) min=getRecordScore(i,rdx);
        }
        return min;
}
int Students::getScoreMax(int rdx){
        int max=-1,i;
        for(i=1;i<=len;i++){
            if(getRecordScore(i,rdx)>max) max=getRecordScore(i,rdx);
        }
        return max;
}
