#ifndef __VECTOR_H
#define __VECTOR_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include "Exceptions.h"
using namespace std;
template <class T>
class Vector {
public:
	Vector();		// create an empty vector
	Vector(int size);	// create a vector of size elements
	inline Vector(const Vector& that){// copy ctor
		*this=that;//just use oprator=
	}
	~Vector(); // Template may not be virtual
	T& operator[](int index) ;
		// return the specified element, throws exception when index <0 or >=m_nSize
	inline int size(){return m_nSize;};		// return the size of the vector
	int inflate(int addSize);	// expand the storage to m_nSize+addSize, return the new size
    operator=(const T& that);
private:
	T *m_pElements;
	int m_nSize;
};
template <class T>
Vector<T>::Vector():m_pElements(NULL),m_nSize(0){};
template <class T>
Vector<T>::Vector(int size):m_nSize(size){
	m_pElements=new T[size];
}
template <class T>
Vector<T>::operator=(const T& that){
    if(this!=&that){
		delete[] this->m_pElements;
	    this->m_nSize=that.m_nSize;
        this->m_pElements=new T[that.m_nSize];
        memcpy(this->m_pElements,that.m_pElements,sizeof(T)*m_nSize);
	}
}
template <class T>
Vector<T>::~Vector(){
	delete[] m_pElements;
}
template <class T>
T& Vector<T>::operator[](int index){
	if(index>=0&&index<m_nSize){
		return m_pElements[index];
	}else{
		throw IndexOutofBounds();
	}
}
template <class T>
int Vector<T>::inflate(int addSize){
	assert(addSize>0);
	T* old=m_pElements;
	int newsize=m_nSize+addSize;
	try{
	    m_pElements = new T[newsize];
	}catch (bad_alloc& e) {
		cout<<"[Error] inflate failed because of memory shortage";
		m_pElements=old;
		return m_nSize;
	}
	memcpy(m_pElements,old,m_nSize);
	delete old;//do not call ~T
	m_nSize=newsize;
	return newsize;
}
#endif
