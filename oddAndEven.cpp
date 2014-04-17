#include<iostream>
using namespace std;
#define LEN 7

void f(int a[],const unsigned int len,bool (*judge)(int)){
	int pre=-1;
	int now=0;
	if(len==0)
		return;
	while(now<len){
		if(judge(a[now])){
			
			pre++;
			if(now!=pre){
				a[pre]+=a[now];
				a[now]=a[pre]-a[now];
				a[pre]-=a[now];
			}
		}
		now ++;
	}
}
bool isOdd(int num){
	return (num&1)==0;
}
int main(){
	
	int A[LEN]={1,1,1,4,4,3,5};
	f(A,LEN,isOdd);
	for(int i=0;i<LEN;i++){
		cout<<A[i]<<endl;
	}
	return 1;
}
