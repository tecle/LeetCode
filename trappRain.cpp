#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
    	if(n<=2)
    		return 0;
        //1,increment,0,plank,-1,decrement
        short int state=1;
        int left=-1,right=-1;
        int i;
        int total=0;
        for(i=0;i<n-1;i++){
       		//cout<<"i:"<<i<<",state="<<state<<endl;
            if(state>=0){
                if(A[i]>A[i+1] && left>=0){
                    right=i;
                    total+=f(A,left,right);
                    if(A[right]>=A[left])
                    	left=right;
                    state=-1;
                }else if(A[i]>A[i+1]){
                    left=i;
                    state=-1;
                }else if(A[i]==A[i+1]){
                    state=0;
                }else if(A[i]<A[i+1]){
                    state=1;
                }
            }else{
            	if(A[i]==A[i+1])
            		state=0;
            	else if(A[i]<A[i+1])
            		state=1;
            }
        }
        if(state>=0 && left>=0)
     		total+=f(A,left,n-1);
        return total;
    }
    int f(int A[],int left,int right){
    	cout<<left<<","<<right<<endl;
        int low=min(A[left],A[right]);
        int total=0,tmp;
        for(unsigned int i=left+1;i<right;i++){
            tmp=low-A[i];
            if(tmp>0){
            	total+=tmp;
            	A[i]=low;
            }
        }

        return total;
    }
};
int main(){
	int A[6]={5,2,1,2,1,5};
	Solution s;
	vector<int> v(5,1);
	cout<<v[0]<<endl;
	cout<<s.trap(A,6)<<endl;
	return 0;
}
