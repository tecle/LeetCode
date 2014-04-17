#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m=grid.size()-1,n=grid[0].size()-1;
        
        return f(grid,m,n);
    }
    int f(vector<vector<int> >&v,int i,int j){
        cout<<i<<","<<j<<endl;
		if(i==0 && j==0 ){
            v[i][j]=-v[i][j];
            return -v[i][j];
        }
        //if this point is in the first line
        if(i==0 && v[0][j-1]<0){
            v[0][j]=v[0][j-1]-v[0][j];
            return -v[0][j];
        }else if(i==0){
            v[0][j]=-(f(v,0,j-1)+v[0][j]);
            return -v[0][j];
        }
        //if this point is in th leftst line
        if(j==0 && v[i-1][0]<0){
            v[i][0]=v[i-1][0]-v[i][0];
            return -v[i][0];
        }else if(j==0){
            v[i][0]= -(f(v,i-1,0)+v[i][0]);
            return -v[i][0];
        }
        //normal point
        int upper,left;
        //left
        if(v[i][j-1]<0)
            left=-v[i][j-1];
        else
            left=f(v,i,j-1);
        //upper
        if(v[i-1][j]<0)
            upper=-v[i-1][j];
        else
            upper=f(v,i-1,j);
            
        v[i][j]=-(min(left,upper)+v[i][j]);
        return -v[i][j];
    }
};

int main(){
	vector<vector<int> > vv;
	int m,n,digit;
	cin>>m;
	cin>>n;
	for(int i=0;i<m;i++){
		vector<int>v;
		for(int j=0;j<n;j++){
			cin>>digit;
			v.push_back(digit);
		}
		vv.push_back(v);
	}
	Solution s;
	cout<<s.minPathSum(vv)<<endl;
	for(m=0;m<vv.size();m++)
		for(n=0;n<vv[0].size();n++)
			cout<<vv[m][n]<<endl;
	return 1;
}


