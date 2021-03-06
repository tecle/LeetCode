#include"myhead.h"
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size())
            return false;
        return f(s1,s2,s3,0,0,0);
    }
    bool f(string &s1,string &s2,string &s3,int i,int j,int k){
        int len1=s1.size(),len2=s2.size(),len3=s3.size();
        if(i == len1 &&  j==len2 && k==len3){
            return true;
        }
        
        if(i<len1 && j<len2 && k<len3){
            bool tmp=false;
            if(s1[i]==s3[k])
                tmp=f(s1,s2,s3,i+1,j,k+1);
            if(s2[j]==s3[k])
                tmp=( tmp || f(s1,s2,s3,i,j+1,k+1) );
            return tmp;
        }
        
        if(i>=len1){
            if(s2.substr(j,len2-j) != s3.substr(k,len3-k))
                return false;
        }
        if(j>=len2){
            if(s1.substr(i,len1-i) != s3.substr(k,len3-k))
                return false;
        }
        return true;
        
    }
    
};

int main(){
	string str1,str2,str3;
	cin>>str1>>str2>>str3;
	Solution s;
	cout<<s.isInterleave(str1,str2,str3)<<endl;

}
