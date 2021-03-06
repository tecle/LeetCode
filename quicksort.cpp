#include<iostream>
#include<vector>
using namespace std;
void exchange(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
int partition(int A[],int begin,int end){
	int flag=A[end];
	//比哨兵小的元素的起始地址不存在。
	int i=begin-1;
	//使用增量的方式来进行分割，每次扩大一个空间，刚开始大小为一，空间下标为begin，同时，比哨兵小的值的最大下标为i
	for(int j=begin;j<end;j++){
		//新加入的元素比哨兵小，则，i增加一，否则i保持不变
		if(A[j]<=flag){
			i++;
			exchange(A[i],A[j]);
		}
	}
	//循环结束后，比哨兵小的元素在[begin,i]中，比哨兵大的元素在[i+1,end-1]中
	//进行交换之后，分别变为[begin,i],[i+2,end]，哨兵位置在i+1
	exchange(A[i+1],A[end]);
	return i+1;
		
}
void quickSort(int A[],int begin,int end){
	if(begin>=end)
		return;
	int flag=partition(A,begin,end);
	quickSort(A,begin,flag-1);
	quickSort(A,flag+1,end);
}
int main(){
	int A[10]={1,2,0};
	int c=100;
	vector<int> a(c);
	quickSort(A,0,3);
	for(int i=0;i<10;i++)
		cout<<A[i]<<endl;
}
