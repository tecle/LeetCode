#include "myhead.h"
class Solution {
public:
    int rows,cols;
    bool ans;
    vector<vector<bool> >flag;
    bool exist(vector<vector<char> > &board, string word) {
        rows=board.size();
        if(rows==0)
            return false;
            
        ans=false;
        cols=board[0].size();
        
        vector<bool> v(cols,false);
        for(int i=0;i<rows;i++)
            flag.push_back(v);
        
        int i=0,j=0;
        for(auto &v_row:board){
        	j=0;
        	for(auto &ele:v_row){
        		if(word[0]==ele){
        			dfs(board,word,i,j,0);
		    		if(ans)
		    			return ans;
        		}
        		j++;
        	}
        	i++;
        }
        return ans;
    }
    void dfs(vector<vector<char> > &board,string &word,int row,int col,int pos){
        
        
        //边界判断
        if(row<0 || col<0)
            return;
        
        if(row>=rows || col >=cols || pos >=word.size()){
            return;
        }
        
        //判断当前点是否已经访问过了
        if(flag[row][col])
            return;
        
        //判断当前点和字符串指定点是否相等
        if(word[pos] != board[row][col])
            return;

        //如果判断到了最后一个字符
        if(pos==word.size()-1 ){
            ans=true;
            return;
        }
        
        if(ans)
            return;
        
        
        //flag current character is used
        flag[row][col]=true;
        
        dfs(board,word,row-1,col,pos+1);
        dfs(board,word,row+1,col,pos+1);
        dfs(board,word,row,col-1,pos+1);
        dfs(board,word,row,col+1,pos+1);
        
        flag[row][col]=false;
    }
};

int main(){
	vector<vector<char> > vb;
	vector<char> v0={'a','b'};
	vb.push_back(v0);
	string str="aa";
	Solution s;
	cout<<s.exist(vb,str)<<endl;
	
}
