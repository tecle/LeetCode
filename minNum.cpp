#include"myhead.h"

/*z找到大于一个数的最小不重复数
 注：写错了
 98999会出现错误答案
*/

void deal(string &num,int start,string &ans){
	int len=num.size();
	if(start == len-1){
		if(num[start] == '9' && len==1){
			ans+="10";
			return;
		}else if(num[start] == '9'){
			ans.append(1,'0');
			ans[start-1]=ans[start-1]+1;
			if(len==2)
				return;
			if(ans[start-2] == ans[start -1])
				ans[start -1]++;
			return;
		}
		ans.append(1,num[start]+1);
		return;
	}
	if(num[start]=='9' && num[start+1]=='9'){
		ans+="10";
		int j=0;
		for(int i=start+1;i<len;i++){
			ans.append(1,j+'0');
			j=(j+1)%2;
		}
		return;
	}
	if(num[start]=='9' && num[start+1]=='8'){
		ans+="98";
		deal(num,start+2,ans);
		return;
	}
	if(num[start]!=num[start+1]){
		ans.append(1,num[start]);
		deal(num,start+1,ans);
		return;
	}
	ans.append(1,num[start]);
	ans.append(1,num[start]+1);
	int j=0;
	for(int i=start+2;i<len;i++){
		ans.append(1,j+'0');
		j=(j+1)%2;
	}
}

int main(){
	string s="2222";
	
	while(cin>>s){
		string sout;
		deal(s,0,sout);
		cout<<sout<<endl;
	}

}
