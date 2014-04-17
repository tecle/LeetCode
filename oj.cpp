#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        if(numRows>=1){
            vector<int> v1;
            v1.push_back(1);
            ans.push_back(v1);
        }
        if(numRows>=2){
            vector<int> v2;
            v2.push_back(1);
            v2.push_back(1);
            ans.push_back(v2);
        }
        for(int i=2;i<numRows;i++){
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<i;j++){
                v.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};
int main(){
	Solution s;
	s.generate(4);
	return 0;
}


