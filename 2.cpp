#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	if(n==0)
    		return ;
        int i=0,j=0;
        for(i=0;i<m;i++)
            A[i+n]=A[i];
        i=0;
        while(i<=m-1 || j<=n-1){
        	cout<<i<<","<<j<<endl;
            if(i>m-1){
                while(j<=n-1){
                    A[i+j]=B[j];
                    j++;
                }
                break;
            }else if(j>n-1)
            	break;
            if(A[i+n]<B[j]){
                A[i+j]=A[i+n];
                i++;
            }else{
                A[i+j]=B[j];
                j++;
            }
        }
    }
};
void print(int A[],int m){
	for(int i=0;i<m;i++)
		cout<<A[i]<<",";
	cout<<endl;
}
int main(){
	int A[100];
	int B[4]={1,3,5,6};
	A[0]=2;
	Solution s;
	s.merge(A,1,B,1);
	print(A,10);
	return 0;
}
