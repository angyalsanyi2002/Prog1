#include <iostream>

using namespace std;

template<class T>
class A{
    public:
    T point;
    virtual T abs(T n) = 0;  
};

template<class T>
class  B: public A<T>{
    public:
    T abs(T n){ return n*-1; };
};

int main (){
    B<int> b;
    cout << b.abs(8);

cout  << endl;
return 0;
}


/*
<template <typename T>

class A (absztrakt)

class B:A

new B
*/
