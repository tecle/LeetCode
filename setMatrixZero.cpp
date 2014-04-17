#include "myhead.h"
class Solution {
public:
    void setZeroes(vector<vector<int> > &v) {
        int m=v.size();
        if(m<=0)
            return;
        int n=v[0].size();
        vector<int> rcd(n);
        int i,k,j;
        for(i=0;i<n;i++)
            rcd[i]=0;
        bool isToZero=false;
        for(i=0;i<m;i++){
            isToZero=false;
            for(j=0;j<n;j++){
                if(v[i][j]==0 && rcd[j]==1){ 
                    rcd[j]=1;
                    isToZero=true;
                }else if(v[i][j]==0 && rcd[j]==0){
                    for(k=i-1;k>=0;k--)
                        v[k][j]=0;
                    rcd[j]=1;
                    isToZero=true;
                }
                else if(rcd[j]==1)
                    v[i][j]=0;
                
            }
            if(!isToZero)
                continue;
            for(j=0;j<n;j++){
                v[i][j]=0;
            }
        }
    }
};

int main(){
	vector<vector<int> > v1;
	vector<int> v2={0};
	v1.push_back(v2);
	Solution s;
	s.setZeroes(v1);

}
