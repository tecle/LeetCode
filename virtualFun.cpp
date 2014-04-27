#include<iostream>
using namespace std;

class A{
public:
	A(){}
	virtual ~A(){cout<<"~A"<<endl;}
	virtual void ppp(){cout<<"I am v_A!"<<endl;}
	virtual void ppp1(){cout<<"I am v_A_1"<<endl;}
};

class B:public A{
public:
	B(){}
	virtual ~B(){cout<<"~B"<<endl;}
	virtual void ppp(){cout<<"I am v_B!"<<endl;}
	virtual void ppp1(){cout<<"I am v_B_1"<<endl;}
};

typedef void(*Fun)(void);

int main(){
	//A a;
	B *b=new B;
	A *ptr=b;
	cout<<"addr:"<<(int *)ptr<<endl;
	//(int*)ptr将对象ptr强行转成了一个指向整型x的地址
	//*(int*)ptr代表读取该整型x所指向的值y
	//(int*) *(int*)ptr代表将取得的值y强行转换成指向整型z的地址
	cout<<"func:"<<(int *)*(int *)(ptr)<<endl;
	Fun fun1=(Fun)(*((int *)*(int *)(ptr)+0));
	fun1();
	//B c;
	//Fun funp=(Fun)*((int *)*(int *)(&c)+0);
	//Fun funp2=reinterpret_cast<Fun>((int*)(&b)+0);
	//funp2();
	delete ptr;
}
