#include "myhead.h"

void sunday(vector<char> &source,vector<char> &pattern){
	int slen=source.size();
	int plen=pattern.size();
	vector<int> next(256,plen);
	int i,j;
	//建立next数组，相当于一个简单的map结构，保存的是距离结尾最近的一个char距离pattern头字符的位置
	for(i=0;i<plen;i++)
		next[ (unsigned char)pattern[i] ]=plen-i-1;
	i=0;
	j=0;
	int sp;
	while(i<slen){
		sp=i+plen-1;
		j=plen-1;
		//防止越界
		if(sp>=slen)
			break;
		//在当前位置从后往前匹配
		while(source[sp] == pattern[j]){
			sp--;
			j--;
			if(j<0){
				cout<<"index:"<<i<<endl;
				return;
			}
		}
		//重新设置下一次查找的起始位置
		i+=next[ (unsigned char)source[i+plen] ]+1;
	}
	cout<<"not Found!"<<endl;
}
int main(){
	string str1,str2;
	vector<char> v1;
	vector<char> v2;
	while(cin >> str1){
		cin>>str2;
		v1.clear();
		v2.clear();
		for(char &ch:str1)
			v1.push_back(ch);
		for(char &ch:str2)
			v2.push_back(ch);
		sunday(v1,v2);
	}

}
