#ifndef __ONECLASS_H
#define __ONECLASS_H
#include <string>
#include <vector>
#include <map> 
using namespace std;
class Classes{
private:
	map<string,vector<int> > data;/*all things in one member*/
public:
	inline void inputOneScore(string& classname,int onescore){
	    data[classname].push_back(onescore);
	}
	double getAverage(string& classname);
	inline int size(){
		return data.size();
	}
	void printSummary();/*summary must be a member function, otherwise (for using iterator) we must make data public*/
};
#endif
