#include "myhead.h"
void way1(string &ch,int head){
	if(head==ch.size()-1){
		cout<<ch<<endl;
		return;
	}
	char tmp;
	int len=ch.size();
	for(int i=head;i<len;i++){
		tmp=ch[i];
		ch[i]=ch[head];
		ch[head]=tmp;
		way1(ch,head+1);
	}
}
//当字符串有重复字符的时候,方法有错误，当输入abbb时有重复
void way3(string &ch,int head){
	if(head==ch.size()-1){
		cout<<ch<<endl;
		return;
	}
	char tmp;
	int len=ch.size();
	way3(ch,head+1);
	for(int i=head+1;i<len;i++){
		if(ch[i]!=ch[head]){
			tmp=ch[i];
			ch[i]=ch[head];
			ch[head]=tmp;
			way3(ch,head+1);
		}
	}
}
//当字符串中有重复的时候,使用set来去重
void way2(string &ch,int head,unordered_set<string> &repeat){
	//cout<<repeat.count(ch)<<endl;
	if(head==ch.size()-1 && repeat.count(ch)==0){
		cout<<ch<<endl;
		repeat.insert(ch);
		return;
	}
	char tmp;
	int len=ch.size();
	for(int i=head;i<len;i++){
		tmp=ch[i];
		ch[i]=ch[head];
		ch[head]=tmp;
		way2(ch,head+1,repeat);
	}
}
int main(){
	string str;
	unordered_set<string> tmp;
	while(cin>>str)	
		//way2(str,0,tmp);
		way3(str,0);
	
}
