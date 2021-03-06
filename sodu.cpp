#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int size=board.size();
        int times;
        for(int i=0;i<size;i++){
            vector<int> row(size,0);
            vector<int> column(size,0);
            for(int j=0;j<size;j++){
                if(board[i][j]!='.'){
                    times=++row[int(board[i][j]-'0')];
            
                    if(times>1)
                        return false;
                }
                if(board[j][i]!='.'){
                    times=++column[int(board[j][i]-'0')];
                    cout<<int(board[j][i]-'0')<<endl;
                    if(times>1)
                        return false;
                }
            }
        }
        return true;
    }
};
int main(){
	vector<vector<char> > vv;
	vector<char> v;
	v.push_back('2');
	v.push_back('.');
	v.push_back('1');
	vv.push_back(v);
	vv.push_back(v);
	vv.push_back(v);
	Solution s;
	cout<<s.isValidSudoku(vv)<<endl;
	
}
