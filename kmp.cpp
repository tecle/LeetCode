#include"myhead.h"
/*KMP算法*/

bool kmp(string &s0,string &s1){
	int len0=s0.size(),len1=s1.size();
	
	//构造next数组
	vector<int> next(len1,-1);
	int j=0;
	for(int i=0;i<len1;i++){
		if(i==0){
			next[i]=0;
			continue;
		}
		j=next[i-1];
		while(j>0 && s1[i] != s1[j])
			j=next[j];
		if(s1[i] == s1[j])
			next[i]=j+1;
		else
			next[i]=j;
	}
	
	//匹配
	int i=0;
	int cnt=0;
	while(i<len0){
		j=0;
		cout<<++cnt<<endl;;
		
		while(i<len0 && s0[i] == s1[j]){
			i++;j++;
		}
		//匹配成功
		if(j==len1)
			return true;
		//匹配失败
		if(i==len0)
			return false;
			
		if(j==0)
			i++;
		else
			i+=(next[j-1]+1);
	}
	return false;
}
int main(){
	string s0="bacbababaabcbab";
	string s1="ababaca";
	cout<<kmp(s0,s1)<<endl;
	}
