#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Dairy.h"
using namespace std;

int main(int argc,char* argv[]){
    Dairy a(default_filename);
    stringstream tmp;
    if(argc==3) {
        int begin,end;
        tmp<<argv[1];
        tmp>>begin;
        tmp.clear();
        tmp<<argv[2];
        tmp>>end;
        a.pdlist(begin,end);
    }else if(argc==1) {
        a.pdlist();
    }else{
        cout<<"Usage example: pdlist 20160101 20161231";
    }
    return 0;
}

