#include "myhead.h"
/*
	数组的子数组之和的最大值
*/
int deal(vector<int> &ary){
	int len = ary.size();
	int max=INT_MIN,cur=0;
	bool isHavePositive=false;
	//先看是否有正数
	for(int i=0;i<len;i++){
		if(ary[i]>0){
			isHavePositive=true;
			break;
		}
		if(ary[i]>max)
			max=ary[i];
	}
	//没有正数
	if(!isHavePositive)
		return max;
		
	//含有正数
	for(int i=0;i<len;i++){
		cur+=ary[i];
		if(cur>max)
			max=cur;
		if(cur<0)
			cur=0;
	}
	return max;
}

int main(){
	vector<int> v={0,-2,3,5,-1,2};
	cout<<deal(v)<<endl;
}
