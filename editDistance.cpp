#include "myhead.h"
class Solution {
public:
    int minDistance(string word1, string word2) {
        //动态规划
        
        int len1=word1.size(),len2=word2.size();
        
        vector<int> v(len2,-1);
        vector<vector<int> > flag(len1,v);
        return D(word1,word2,len1,len2,flag);

    }
    int D(string &s1,string &s2,int i,int j,vector<vector<int> > &flag){
    	if(i==0)
    		return j;
    	if(j==0)
    		return i;
        
        if(flag[i-1][j-1]>=0)
            return flag[i-1][j-1];
        
        int a,b,c;
        a=D(s1,s2,i-1,j,flag)+1;
        b=D(s1,s2,i,j-1,flag)+1;
        c=D(s1,s2,i-1,j-1,flag);
        if(s1[i-1]!=s2[j-1])
            c+=1;
        flag[i-1][j-1]= min( min(a,b),c);
        return flag[i-1][j-1];
    }
};

int main(){
	string s1="abcvdfsdfasdfeeewrewqr";
	string s2="baasdfaaa";
	Solution s;
	cout<<s.minDistance(s1,s2)<<endl;
}
