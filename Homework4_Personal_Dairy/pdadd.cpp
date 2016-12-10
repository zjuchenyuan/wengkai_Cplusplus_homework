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

int main(){
    string d,content;
    getline(cin,d);
    do{
        content+=d+"\n";
        getline(cin,d);
    }while(d!="."&&!cin.eof());
    content.erase(content.size()-1);//discard the '\n'
    Dairy a(default_filename);
    a.pdadd(Dairy::today(),content);
    return 0;
}

