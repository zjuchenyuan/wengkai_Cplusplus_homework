#ifndef __STUDENTS_H
#define __STUDENTS_H
#include <iostream>
#include <string>
#include "Record.h"
using namespace std;
class Students{
private:
    pRecord* data;//an array, the element is pointer to one Record 
    int len;//how many record in this Students, actually using len+1 memory units (no using data[0])
    int rlen;//how many score in each record
public:
    Students(int ilen,int irlen);
    ~Students();
    int get_rlen();
    void inputRecordName(int idx,string& name);
    void inputRecordScore(int idx,int rdx,int score);//inputRecordScore(2,1,4) means No.2 Studnets's score1=4
    int getRecordScore(int idx,int rdx);
    double getRecordAverage(int idx);
    string& getRecordName(int idx);
    double getScoreAverage(int rdx);
    int getScoreMin(int rdx);
    int getScoreMax(int rdx);
};
#endif
