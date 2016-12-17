#include <iostream>
#include "Fraction.h"
using namespace std;
int gcd(int a,int b);
int test(){
	Fraction a(0,10),b(-6,18),c(1,3);
	a=a;
	b-=c;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
	cout<<"c="<<c.toString()<<endl;
	
	if(a!=b){
		cout<<"a!=b"<<endl;
	}else{
		cout<<"a==b"<<endl;
	}
	if(a<=c){
		cout<<"a<=c"<<endl;
	}else{
		cout<<"a>c"<<endl;
	}
	
	Fraction d;
	cout<<endl<<"Plz input like 5/10: ";
	cin>>d;
	cout<<"After d++: "<<d++<<endl;
	cout<<"Then ++d: "<<++d<<endl;
	cout<<"At last, --d: "<<--d<<endl;
}
int main(){
	test();
}
