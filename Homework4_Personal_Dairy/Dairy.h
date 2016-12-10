#ifndef __DAIRY_H
#define __DAIRY_H
#define default_filename "data.txt"
#include <string>
#include <vector>
#include <map> 
#include <fstream>
using namespace std;
class Dairy{
private:
	map<int,string> data;
	string fn;//filename
public:
	static int today();
	Dairy(string filename);
	virtual ~Dairy();
	inline void pdadd(int date,string& content){
		data[date]=content;
	}
	void pdlist(int begin=0,int end=99999999,bool friendly=true);
	inline string pdshow(int date=today()){
		map<int,string>::iterator i = data.find(date);
		if(i!=data.end()) return i->second;
		else return "Not found";
	}
	inline int pdremove(int date){
		map<int,string>::iterator i = data.find(date);
		if(i==data.end()) return -1;
		else data.erase(date);
		return 0;
	}
};

#endif
