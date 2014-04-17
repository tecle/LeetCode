#include<iostream>
#include<vector>
using namespace std;
struct Gap{
    int left;
    int right;
    Gap(int x,int y):left(x),right(y){}
    };
class Solution {
public:
    int candy(vector<int> &r) {
        int len_r=r.size();
        if(len_r==0)
            return 0;
        vector<int> c;
        c.push_back(1);
        for(int i=1;i<len_r;i++){
            //small,big,it is a fixed gap
            if(r[i]>r[i-1]){
                c.push_back(c.back()+1);
            //equal ,it is a fixed gap
            }else if(r[i]==r[i-1]){
                c.push_back(1);
            }else{
                //L, it is a unfixed gap,wen c[gap+1] grow to c[gap]-1,this gap will disappear
                if(c[i-1]>1){
                    c.push_back(1);
                }else{
                    adjustCandy(c,i-1);
                    c.push_back(1);
                }
            }
            
        }
        int sum=0;
        for(int j=0;j<c.size();j++)
            sum+=c[j];
        return sum;
    }
    void adjustCandy(vector<int> &v, int tail){
        while(true){
            if(tail==0){
                v[tail]++;
                return;
            }
            if(v[tail-1]-v[tail]<=0 || v[tail-1]-v[tail]>1){
                v[tail]++;
                return;
            }
            v[tail]++;
            tail--;
        }
        
    }
};

int main(){
	Gap g(1,2);
	return 1;
}
