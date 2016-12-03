#include <iostream>
#include <algorithm>  
#include <string>
#include <vector>
#include <map> 
#include "Classes.h"
using namespace std;
double Classes::getAverage(string& classname){
	map<string,vector<int> >::iterator i=data.find(classname);
	if(i==data.end()) return -1;
	else{
		int sum=0;
		vector<int> classdata=i->second;
		vector<int>::iterator j;
		for(j=classdata.begin();j!=classdata.end();j++){
			sum+=*j;
		}
		return (double)sum/classdata.size();
	}
}
void Classes::printSummary(){
	cout<<"========CLASSES STATISTICS========="<<endl;
	cout<<"Total Class:"<<data.size()<<endl;
	map<string,vector<int> >::iterator i;
	for(i=data.begin();i!=data.end();i++){
		string classname=i->first;
		vector<int>::iterator biggest = max_element(i->second.begin(), i->second.end()); 
		vector<int>::iterator smallest = min_element(i->second.begin(), i->second.end()); 
		cout<<"Class "<<classname<<": Size: "<<i->second.size()<<";Average: "<<getAverage(classname)<<";Min: "<<*smallest<<";Max: "<<*biggest<<endl;
	}
}
