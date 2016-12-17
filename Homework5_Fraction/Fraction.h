#ifndef __FRACTION_H
#define __FRACTION_H
#define WARNING 1 
#include <iostream>
#include <string>
using namespace std;
class Fraction{
private:
    int a;//分子
    int b;//分母 
    void yuefen();//执行约分，构造函数和inserter需要调用 
public:
    inline Fraction():a(1),b(1){
        if(WARNING) cout<<"[Warning] default ctor, using 1/1"<<endl;
    };
    inline Fraction(int ia,int ib):a(ia),b(ib){
        yuefen();
    };
    Fraction& operator=(const Fraction& that); 
    inline Fraction(const Fraction& that){
        *this=that;
    }
    inline virtual ~Fraction(){};
    const Fraction operator+(const Fraction& that) const;
    inline Fraction& operator+=(const Fraction& that){
        *this=*this+that;
        return *this;
    }
    const Fraction operator-(const Fraction& that) const;
    inline Fraction& operator-=(const Fraction& that){
        *this=*this-that;
        return *this;
    }
    const Fraction operator*(const Fraction& that) const;
    inline Fraction& operator*=(const Fraction& that){
        *this=*this*that;
        return *this;
    }
    const Fraction operator/(const Fraction& that) const;
    inline Fraction& operator/=(const Fraction& that){
        *this=*this/that;
        return *this;
    }
    bool operator<(const Fraction& that) const;
    inline bool operator>=(const Fraction& that) const{
        return !(*this<that);
    }
    inline bool operator>(const Fraction& that) const{
        return that< *this;
    }
    inline bool operator<=(const Fraction& that) const{
        return !(that<*this);
    }
    bool operator==(const Fraction& that);
    inline bool operator!=(const Fraction& that){
        return !(*this==that);
    }
    inline operator double(){
        return a/(double)b;
    }
    string toString();
    inline void show() const{
        cout<<*this;
    }
    friend ostream& operator<<(ostream& os,const Fraction& obj);
    friend istream& operator>>(istream& is,Fraction& obj);
    inline const Fraction& operator++(){
        Fraction tmp(1,1);
        *this+=tmp;
        return *this;
    }
    inline const Fraction operator++(int){
        Fraction tmp1=*this,tmp2(1,1);
        *this+=tmp2;
        return tmp1;
    }
    inline const Fraction& operator--(){
        Fraction tmp(1,1);
        *this-=tmp;
        return *this;
    }
    inline const Fraction operator--(int){
        Fraction tmp1=*this,tmp2(1,1);
        *this-=tmp2;
        return tmp1;
    }    
};
#endif
