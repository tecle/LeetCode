#include "myhead.h"
class Solution {
public:
    int row,col;
    void solve(vector<vector<char>> &board) {
        row=board.size();
        if(row==0)
            return;
        col=board[0].size();
        if(row==1 || col <=1)
            return;
        int i,j;
        i=0;
        for(j=0;j<col-1;j++)
            if(board[i][j]=='O')
                reserve(board,i,j);

        for(i=0;i<row-1;i++)
            if(board[i][j]=='O')
                reserve(board,i,j);

        for(j=col-1;j>0;j--)
            if(board[i][j]=='O')
                reserve(board,i,j);

        for(i=row-1;i>0;i--)
            if(board[i][j]=='O')
                reserve(board,i,j);
        

        
        for(auto &rows:board)
            for(auto &ch:rows)
                if(ch=='O')
                    ch='X';
                else if(ch=='#')
                    ch='O';
        
    }
    void reserve(vector<vector<char>> &v,const int i,const int j){
    	static int cnt=0;
    	cnt++;
    	cout<<cnt<<endl;
    	int iii=cnt;
        if(i<0||j<0)
            return;
        if(i>row-1 || j>col-1)
            return;
        if(v[i][j]=='X' || v[i][j]=='#')
            return;
        v[i][j]='#';
        //cout<<i<<"."<<j<<endl;
		int ii=i-1,jj=j;
		//upper point
		while(ii>=0 && v[ii][jj]=='O'){
			v[ii][jj]='#';
			//cout<<ii<<",^"<<jj<<endl;
			reserve(v,ii,jj-1);
			reserve(v,ii,jj+1);
			ii--;
		}
		ii=i;
		jj=j-1; 
		while(jj>=0 && v[ii][jj]=='O'){
			v[ii][jj]='#';
			//cout<<ii<<",<"<<jj<<endl;
			reserve(v,ii-1,jj);
			reserve(v,ii+1,jj);
			jj--;
		}
		jj=j;
		ii=i+1;
		while(ii<row && v[ii][jj]=='O'){
			v[ii][jj]='#';
			//cout<<ii<<",v"<<jj<<endl;
			reserve(v,ii,jj-1);
			reserve(v,ii,jj+1);
			ii++;
		}
		ii=i;
		jj=j+1;
		while(jj<col && v[ii][jj]=='O'){
			v[ii][jj]='#';
			//cout<<ii<<",>"<<jj<<endl;
			reserve(v,ii+1,jj);
			reserve(v,ii-1,jj);
			jj++;
		}
        
        cout<<"free:"<<iii<<endl;
    }
    void reserve2(vector<vector<char>> &v,const int i,const int j){
    	static int cnt2=0;
    	cnt2++;
    	cout<<cnt2<<endl;
        if(i<0||j<0)
            return;
        if(i>row-1 || j>col-1)
            return;
        if(v[i][j]=='X' || v[i][j]=='#')
            return;
        v[i][j]='#';
        reserve(v,i-1,j);
        reserve(v,i,j-1);
        reserve(v,i+1,j);
        reserve(v,i,j+1);
    }
};

int main(){
	vector<vector<char> > input;
	vector<char> tuple={'X','X','X','X','X','X','X'};
	for(int i=0;i<7;i++)
		input.push_back(tuple);
	int i;
	for(i=0;i<5;i++)
		input[i][3]='O';
	for(i=1;i<6;i++)
		input[2][i]='O';
	for(i=3;i<6;i++)
		input[i][5]='O';
	for(i=1;i<4;i++)
		input[3][i]='O';
	input[4][3]='O';
	input[5][4]='O';
	for(auto &row:input){
		for(auto &ele:row)
			cout<<ele<<" ";
		cout<<endl;	
		}
	Solution s;
	s.solve(input);
	for(auto &row:input){
		for(auto &ele:row)
			cout<<ele<<" ";
		cout<<endl;	
		}
	return 1;
}


