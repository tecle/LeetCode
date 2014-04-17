#include "myhead.h"
class Solution {
public:
    int divide(int dividend, int divisor) {
        int i=1;
        int flag=1;
        int &a=dividend,&b=divisor;
        
        if(a==0)
        	return 0;
        	
    	if(b==1 || b==-1)
            return a*b;
        
        
        if(a>0){
        	a=-a;
        	flag=-1;
        }
        
        if(b>0){
        	b=-b;
        	flag=flag*-1;
        }
   
        
        int cnt = 0;
        int tmp;
        // when a/b...a is bigger than b
        while(a <= b){
            a -= b;
            cnt++;
            i=1;    
            // b * 2^i
            tmp=b<<i;
            while(tmp<0 && a <= tmp){
                a -= tmp;
                cnt += (1<<i);//cnt += 2^i;
                i++;//i *= 2;
                tmp=b<<i;
            }
            //cout<<"zzz"<<endl;
        }
        
        return flag*cnt;
    }
};
class A{
public :
	A(){
		cout<<"2"<<endl;
	}
};
int main(){
	Solution s;
	A *a=new A;
	int m=2147483647,n;
	while(cin>>m){
		cin>>n;
		cout<<s.divide(m,n)<<endl;
		}
}
