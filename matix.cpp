#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &v) {
        int tlines=v.size();
        int tmp;
        int i=0;
        while(tlines-2*i>1){
            for(int j=0;j<tlines-2*i-1;j++){
            	cout<<i<<","<<i+j<<endl;
            	cout<<tlines-i-1-j<<","<<i<<endl;
            	cout<<tlines-1-i<<","<<tlines-1-i-j<<endl;
            	cout<<i+j<<","<<tlines-1-i<<endl;
            	cout<<"----"<<endl;
                tmp=v[i][i+j];
                v[i][j+i]=v[tlines-i-1-j][i];
                v[tlines-i-1-j][i]=v[tlines-1-i][tlines-1-i-j];
                v[tlines-1-i][tlines-1-i-j]=v[i+j][tlines-1-i];
                v[i+j][tlines-1-i]=tmp;
            }
            i++;
        }
    }
};
int main(){
	vector<vector<int> >v;
	for(int i=0;i<4;i++){
		vector<int> vv;
		for(int j=4*i;j<4*i+4;j++)
			vv.push_back(j);
		v.push_back(vv);
	}
	Solution s;
	s.rotate(v);
	
}
