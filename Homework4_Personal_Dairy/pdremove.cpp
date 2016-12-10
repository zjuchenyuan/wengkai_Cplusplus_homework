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
    if(argc==2) {
        int date;
        tmp<<argv[1];
        tmp>>date;
        return a.pdremove(date);
    }else{
        cout<<"Usage example: pdremove "<<Dairy::today();
    }
    return 0;
}

