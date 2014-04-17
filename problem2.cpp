#include<iostream>
#include<stdlib.h>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<limits.h>
using namespace std;

int f(int a[],int n,int start){
	int i=start;
	int j=start+1;
	int pre=start,len;
	int max=0,headj;
	while(true){
		i=start;
		j=pre+1;
		//找到第一个和i相等的数
		while(j<n && a[i]!=a[j]){
			j++;
		}
		//cout<<a[j]<<endl;
		//没有找到，返回
		if(j==n)
			return max;
		headj=j;
		pre=j;
		//要求i的最大值要小于j的起始值，也就是pre+1
		while(i<headj && j<n && a[i]==a[j]){
			i++;
			j++;
			
		}
		//find a repeat str
		len=j-pre;
		if(max<len)
			max=len;
	}
	return max;
}

int main(){
	int i,j,k;
	int a[300];
	std::cin>>i;
	j=0;
	while(j<i){
		std::cin>>a[j];
		j++;
	}
	int max=0,tmp;
	for(k=0;k<i;k++){
		tmp=f(a,i,k);
		if(tmp>max)
			max=tmp;
	}
	std::cout<<max<<std::endl;

	return 0;
}
