#include<iostream>
using namespace std;
#define ROW 1
#define COL 1
class Solution{
public:
void printNum(int m0,int n0,int m1,int n1){
	if(m0>m1 || n0>n1)
		return;
	
	int i=m0;
	int j=n0;
	for(j=n0;j<=n1;j++)
		cout<<A[i][j]<<endl;
	if(m0==m1)
		return;
	j=n1;
	for(i=m0+1;i<=m1;i++)
		cout<<A[i][j]<<endl;
	if(n0==n1)
		return;
	i=m1;
	for(j=n1-1;j>=n0;j--)
		cout<<A[i][j]<<endl;
	j=n0;
	for(i=m1-1;i>=m0+1;i--)
		cout<<A[i][j]<<endl;
	printNum(m0+1,n0+1,m1-1,n1-1);
}
int A[ROW][COL];
void init(){
	int cnt=0;
	for(int i=0;i<ROW;i++)
		for(int j=0;j<COL;j++){
			A[i][j]=cnt;
			cnt++;
		}
}
};
int main(){
	Solution s;
	s.init();
	s.printNum(0,0,ROW-1,COL-1);
	return 1;
}

