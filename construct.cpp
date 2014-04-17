#include "myhead.h"
class X{
public:
	int x;
	X(){cout<<"X()"<<endl;}
	X(const X& a){x=a.x;cout<<"X(const X&)"<<endl;}
	X& operator=(const X&a){
		cout<<"="<<endl;
		x=a.x;
		return *this;	
	}
};
int num;
class Y{
public:
	int sn;
	Y():sn(num){
		num++;
	}
	Y(const Y & y){
		sn=num++;
	}
};
void prt(X x){
	;
}
void prty(const Y& y){
	cout<<y.sn<<endl;
}
int main(){
	num=1;
	Y y0,y1=y0,y2=y0;
	prty(y0);
	prty(y1);
	
	X x;
	x.x=2;
	X y=x;
	X z;
	z=x;
	cout<<endl;
	vector<X> v;
	v.push_back(x);
	v.push_back(y);
	cout<<endl;
	prt(x);
	return 1;
}
