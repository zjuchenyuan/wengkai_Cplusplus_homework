#ifndef __RECORD_H
#define __RECORD_H
#include <string>
using namespace std;
class Record{
private:
    string name;
    int* score;
    int len;//how many score in this record, actually using len+1 memory units (no using score[0])
public:
    Record(int ilen);
    ~Record();
    void inputname(string& iname);
    string& getname();
    bool inputscore(int idx,int iscore);
    int getscore(int idx);
    double getaverage();
};

typedef Record* pRecord;
#endif
