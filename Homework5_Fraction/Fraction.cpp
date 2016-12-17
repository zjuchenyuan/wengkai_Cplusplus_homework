#include "Fraction.h"
#include <iostream>
#include <sstream>
using namespace std;
int gcd(int a,int b){
    if(a>b) return gcd(b,a);
    else if(a<0) return gcd(-a,b);
    else if(a==b||a==0) return b;
    else return gcd(a,b%a);
}
void Fraction::yuefen(){
    int t=gcd(a,b);
    a/=t;
    b/=t;
}
Fraction& Fraction::operator=(const Fraction& that){
    if(this!=&that){
        this->a=that.a;
        this->b=that.b;
    }else{
        if(WARNING) cout<<"[Warning] *this==that happens! do nothing..."<<endl;
    }
}; 
const Fraction Fraction::operator+(const Fraction& that) const{
    return Fraction(this->a*that.b+this->b*that.a,
                    this->b*that.b);
};
const Fraction Fraction::operator-(const Fraction& that) const{
    return Fraction(this->a*that.b-this->b*that.a,
                    this->b*that.b);
};
const Fraction Fraction::operator*(const Fraction& that) const{
    return Fraction(this->a*that.a,this->b*that.b);
};
const Fraction Fraction::operator/(const Fraction& that) const{
    return Fraction(this->a*that.b,this->b*that.a);
};
bool Fraction::operator<(const Fraction& that) const{
    return this->a*that.b-this->b*that.a<0;
}
bool Fraction::operator==(const Fraction& that){
    yuefen();
    Fraction tmp(that);
    return this->a==tmp.a && this->b==tmp.b;
}
string Fraction::toString(){
    string output;
    stringstream tmp;
    tmp<<(double)(*this);
    tmp>>output;
    return output;
}
ostream& operator<<(ostream& os,const Fraction& obj){
    os<<obj.a<<"/"<<obj.b;
    return os;
}
istream& operator>>(istream& is,Fraction& obj){
    is>>obj.a;
    is.get();
    is>>obj.b;
    obj.yuefen();
    return is;
}
