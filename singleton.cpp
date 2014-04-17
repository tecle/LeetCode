#include"myhead.h"
#include<mutex>
class A{
private:
	A(){}
public:
	int flag;
	static A* getInstance(){
		lock();
		static A a;
		unlock();
		return &a;
	}
};
int main(){
	A *a=A::getInstance();
	a->flag=1;
	A *b=A::getInstance();
	b->flag=2;
	cout<<a->flag<<endl;
}
