#include"myhead.h"
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len=num.size(),i;
        for(i=len-1;i>0;i--)
            if( num[i] > num[i-1])
                break;
        int index=i-1;
        //its a loop,reverse it!
        int head,tail,tmp;
        if(index<0){
            head=0;
            tail=len-1;
            while(head<tail){
                tmp=num[head];
                num[head]=num[tail];
                num[tail]=tmp;
                head++;
                tail--;
            }
            return;
        }
        
        //find first num bigger than num[index]
        for(i=len-1;i>0;i--)
            if( num[i] > num[index])
                break;
        
        //swap number at index and i
        tmp=num[index];
        num[index]=num[i];
        num[i]=tmp;
        
        //reverse number bettween index+1 and len-1
        tail=len-1;
        head=index+1;        

        while(head<tail){
            tmp=num[head];
            num[head]=num[tail];
            num[tail]=tmp;
            head++;
            tail--;
        }
        
    }
};

int main(){
	Solution s;
	vector<int> v={1,2,3};
	for(int i=0;i<6;i++){
		for(auto &ele:v)
			cout<<ele<<" ";
		cout<<endl;
		s.nextPermutation(v);
	}
}
