#include<iostream>
using namespace std;

int left(int i){
	return 2*i;
}
int right(int i){
	return 2*i+1;
}
int parent(int i){
	return i/2;
}
//max heap,chose a max num bettween current node and its left, right node 
void insert(int A[],int size,int pos){
	int largest=pos;
	int l=left(pos),r=right(pos);
	//从当前的三人行(当前节点，左节点，右节点)中找出最大的节点
	if(l<=size && A[pos]<A[l])
		largest=l;
	if(r<=size && A[largest]<A[r])
		largest=r;
	//如果最大的节点不是当前节点，则需要将当前节点和最大的节点交换位置，并且递归进行纠正
	if(largest!=pos){
		int tmp=A[largest];
		A[largest]=A[pos];
		A[pos]=tmp;
		insert(A,size,largest);
		}
}
//bulid a max heap
void bulid(int A[],int size){
	//很明显，最大堆的叶子节点都在后半段，因为，当i>size/2时，left(i)>size，说明没有子节点，也就时i>size/2的节点都是叶子节点。
	//从最后一个非叶子节点开始自底向上进行建堆过程
	for(int i=size/2;i>=1;i--)
		insert(A,size,i);
}
//sort it ,by removing an element in the top ,and replace it with the last element in max heap.
void sort(int A[],int size){
	//进行最后的排序，很明显，最大元素一定在堆顶部，将其和堆的最后一个节点进行交换，这样，堆的大小缩减1
	//同时，重新进行一次最大堆的排序过程
	//一直重复到堆的大小变为1时，此时整个数组变成有序的
	for(int i=0;i<=size-1;i++){
		//exchage A[1]<-->A[end]
		int tmp=A[1];
		A[1]=A[size-i];
		A[size-i]=tmp;
		insert(A,size-i-1,1);
	}
}
void print(int A[],int size){
	for(int i=1;i<=size-1;i++){
		cout<<A[i]<<",";
	}
	cout<<A[size]<<endl;
}
//注意，这个排序算法认为数组的第一个数的下表为1而不是0！
int main(){
	int A[10]={0,2,3,4,6,1,7,5,8,9};
	bulid(A,9);
	print(A,9);
	sort(A,9);
	print(A,9);
}

