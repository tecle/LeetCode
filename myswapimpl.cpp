#include"myhead.h"

class A{
public:
	A(int v,string n):name(n),id(v){}
	virtual ~A(){}
	int id;
	string name;
	
};

//交换两个指针的地址，传入参数是指向模板地址的地址
template <typename T> void myswap(T **a,T **b){
	int a0=reinterpret_cast<int>(*a);
	int b0=reinterpret_cast<int>(*b);
	(*a)=reinterpret_cast<T*>(b0);
	(*b)=reinterpret_cast<T*>(a0);	
}

int main(){
	A *c1=new A(1,"girl");
	A *c2=new A(2,"boy");
	myswap(&c1,&c2);
	cout<<c1->id<<c1->name<<endl;
	cout<<c2->id<<endl;
	std::swap(c1,c2);
	cout<<c1->id<<endl;
}
