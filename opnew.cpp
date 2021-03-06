#include "myhead.h"
/*主要用来测试new的重载*/
class Base{
public:
	Base();
	void * operator new(size_t);
	void operator delete(void *ptr);
	void say();
	char *ch;
	vector<int> v;
};

void Base::say(){
	cout<<"speak"<<endl;
}

Base::Base(){
	cout<<"Construct Base!"<<endl;
}
//重载operator new 
void* Base::operator new(size_t size){
	cout<<"my own new!"<<endl;
	//if(size!=sizeof(Base))
	return static_cast<int*>(::operator new(size));
	
}

void Base::operator delete(void *ptr){
	::operator delete(ptr);
}

class Base0{
public:
	int b[100];
};

int main(){
	Base *b1=new Base;
	//Base *b2=new Base();
	(*b1).say();
	//将b1的地址转换成整型传给ptr
	int ptr= (reinterpret_cast<int> (b1));
	//将整型ptr转换成Base类的地址
	(reinterpret_cast<Base *>(ptr))->say();
	printf("%p\n",b1);
	cout<<sizeof(*b1)<<endl;
	const int cint=2;
	//去掉const限制
	int *new_cint =const_cast<int*>(&cint);
	//这是一个未定义行为
	*new_cint =3;
	//输出结果还是2,const_cast的作用就是实现了常量到非常量的引用
	cout<<cint<<endl;
	
	
    //一个正常的分配。向操作系统请求内存，所以我们并不知道它指向哪里
    int* iptr = new int;
    cerr << "Addr of iptr = " << iptr << endl;


    //创建一块足够大的缓冲区来保存一个整型，请注意它的地址
    char mem[sizeof(int)];
    cerr << "Addr of mem = " << (void*) mem << endl;


    //在缓冲区mem中构造新的整型，地址将变成mem的地址
    int* iptr2 = new (mem) int;
    cerr << "Addr of iptr2 = " << iptr2 << endl;
    //分配一个字符的空间，也就是1BYTE
    char memo[1];
    Base0 *b2=new(memo) Base0;
    //输出地址
    cerr<<"memo addr is:" << (void *)memo<<endl;
    //分配三个字符空间，并初始化
    char memoo[3]={'a','b','d'};
    cerr<<"memoo addr is:";
    cerr << (void *)memoo <<endl;
    //输出字符地址
    cout<<"array b's first addr is:"<<(void *)((*b2).b)<<endl;
    //查看元素的值,这个时候对memoo内容的修改会导致第一个数的值出现更改，也就是内存污染
    cout<<"value:"<<(b2->b)[0]<<endl;
}
