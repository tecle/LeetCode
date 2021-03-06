#include"myhead.h"


/*将一个数组进行模3排序*/

void deal(vector<int> &nums){
	int ptr0=-1,ptr1=-1,ptr2=-1;//第一个指向最后一个模3等于0的位置，第二个指向最后一个模3等于1的位置
	int len=nums.size();
	int tmp;
	for(int i=0;i<len;i++){
		if(nums[i]%3 == 0){
			ptr0++;
			ptr1++;
			ptr2++;
			tmp=nums[i];
			nums[ptr2]=nums[ptr1];
			nums[ptr1]=nums[ptr0];
			nums[ptr0]=tmp;
			}
		else if(nums[i]%3 == 1){
			ptr1++;
			ptr2++;
			tmp=nums[ptr2];
			nums[ptr2]=nums[ptr1];
			nums[ptr1]=tmp;
		}else{
			ptr2++;
		}
	}
	for(auto &ins:nums){
		cout<<ins<<"["<<ins%3<<"]"<<endl;
	}

}


int main(){
	vector<int> num={3,6,9,1,7,2,9,9,9};
	deal(num);
}


