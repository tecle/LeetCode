#include "myhead.h"

class Solution {
public:
    int f(vector<int> &num) {
        map<int,int> m;
        int i,len=num.size(),max=0;
        for(i=0;i<len;i++){
            m[num[i]]=1;
        }
        int left,right,curL,curR;
        for(int i=0;i<len;i++){
            left=0;
            right=0;
            curL=num[i];
            curR=num[i];
            while(true){

                if(m[--curL]==1){
                    left++;
                    m[curL]=-1;
                }
                else
                    break;
            }
            while(true){
                if(m[++curR]==1){
                    right++;
                    m[curR]=-1;
                }else
                    break;
            }
            if(left+right+1>max)
                max=left+right+1;
            
        }
        return max;
    }
};

int main(){
	vector<int> num={0,-1,2,1,3,5};
	Solution s;
	cout<<s.f(num)<<endl;

}
