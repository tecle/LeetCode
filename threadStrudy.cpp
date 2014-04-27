#include<iostream>
#include<pthread.h>
using namespace std;

#define T_NUM 5

/*编译多线程时需要加上 -lpthread 参数，使用静态库*/

void * say_hello(void * args){
	while(true){
	cout<<"hello word!"<<*((int *)args)<<endl;
	}
}

int main(){
	pthread_t tids[T_NUM];
	for(int i=0;i<T_NUM;i++){
		int ret=pthread_create(&tids[i],NULL,say_hello,&i);
		if(ret!=0)
			cout<<"thread create success!"<<endl;
	}
	//pthread_exit(NULL);
}

