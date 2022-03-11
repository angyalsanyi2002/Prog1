#include <string>
#include <iostream>
using namespace std;

class B1 {
	public:
		virtual void vf() { cout << "B1::vf()" << endl;}
		void f() {cout << "B1::f()" << endl;}
		//virtual void pvf() = 0;		//üres fv, nem értelmezhető, tisztán 			  virtuális-> absztrakt-> absztrakt osztály, nem példányosítható

		
};
				//protected esetén public->prot, prot->prot priv->priv
class D1 : public  B1 {		//D1 public módon örököl a B1-től, ami B1-ben priv, pub, prot, ugyanúgy 
	public:			//örökli D1, láthatóság megmarad
		void vf() { cout << "D1::vf()" << endl;}
		void f() { cout << "D1::f()"  <<'\n';}		
};

class D2 : public D1 {
	public:
		void pvf() { cout << "D2::pvf()" << endl;}
};

class B2 {
	public:
		virtual void pvf() = 0;
};
	
class D21 : public B2{				//nem absztrakt, mert felülírtuk
	public:
		string s;
		void pvf(){cout << s << endl;}
}; 

class D22 : public B2{				//nem absztrakt, mert felülírtuk
	public:
		int n;
		void pvf(){cout << n << endl;}
}; 

void f(B2& b2ref){
	b2ref.pvf();
};

int main(){
	
	B1 b1;		//B1: osztály b1:példány
	b1.vf();
	b1.f();
	
	D1 d1;
	d1.vf();
	d1.f(); 
	
	B1& bref = d1;	//B1 referencia, egyenlővé tesszük d1 obj-mal
	bref.vf();	//d1 tulajdonságait megtartva saját f(), vf()-et használja
	bref.f();
	
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();
	
	D21 d21;
	d21.s = "d21.s";
	d21.pvf();
	
	D22 d22;
	d22.n = 22;
	d22.pvf();
	
	f(d21);
	f(d22);
	
}
