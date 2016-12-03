#include <iostream>
#include <string>
#include "Record.h"
Record::Record(int ilen):len(ilen){
        score = new int[ilen+1];
};
Record::~Record(){
        delete[] score;
};
void Record::inputname(string& iname){
        name = iname;
}
string& Record::getname(){
        return name;
}
bool Record::inputscore(int idx,int iscore){
    /*
     * inputscore(1,5) means score1=5;
     * return False when idx > len
     */
        if(idx>len) return false;
        score[idx] = iscore;
        return true;
}    
    
int Record::getscore(int idx){
        return score[idx];
}

double Record::getaverage(){
        int i,sum=0;
        for(i=1;i<=len;i++){
            sum+=getscore(i);
        }
        return (double)sum/len;
}
