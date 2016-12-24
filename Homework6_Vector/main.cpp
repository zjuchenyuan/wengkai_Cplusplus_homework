#include <iostream>
#include "Vector.h"
#include "Exceptions.h"
using namespace std;
class Test{
public:
    Test(){
        cout<<"Test::Test()"<<endl;
    }
    ~Test(){
        cout<<"Test::~Test"<<endl;
    }
};
int main(){
    Vector<int> a(10),b;
    a[5]=99;
    b=a;
    cout<<"b=a success!"<<endl;
    try{
        cout<<"b[5]="<<b[5]<<endl;
    }
    catch(Exception& e){
        e.diagnose();
    }
    try{
        b[99]=99;
    }
    catch(Exception& e){
        e.diagnose();
    }
    cout<<"a.inflate(100)="<<a.inflate(100)<<endl;
    cout<<"b.size()="<<b.size()<<endl;
    
    Vector<Test> c(1);
}
