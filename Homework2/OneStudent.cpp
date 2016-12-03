#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include "OneStudent.h"
double OneStudent::getaverage(){
	if (stuscore.empty()) return -1;
	else{
        int sum=0;
        map<string,int>::iterator i;
        for(i=stuscore.begin();i!=stuscore.end();i++){
            sum+=i->second;
        }
        return (double)sum/stuscore.size();
    }
}

