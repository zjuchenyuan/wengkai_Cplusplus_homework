#ifndef __EXCEPTION_H
#define __EXCEPTION_H
#include <string>
using namespace std;
class Exception{
public:
	inline virtual void diagnose(){
		cout<<"Exception: "<<reason<<endl;
	}
	Exception(string input):reason(input){};
protected:
	string reason;
};
class IndexOutofBounds:public Exception{
public:
	IndexOutofBounds(string input="Index Out Of Range"):Exception(input){};
};
#endif	
