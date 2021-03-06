#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        //str x char
        string mid;
        string pre="0";
        int offset=0;
        for(int i=num2.size()-1;i>=0;i--){
        	mid=strXchar(num1,num2[i]);
        	//cout<<i<<":"<<mid<<endl;
        	//相加里面有位移
        	pre=add2str(pre,mid,offset);
        	offset++;
        	cout<<"pre:"<<pre<<endl;
        }
        return pre;
    }
    //a*b+c
    //返回的时候高位在后面，低位在前面
    string charXchar(const char &a,const char &b,const char &c){
        int a_i=a-'0';
        int b_i=b-'0';
        int c_i=c-'0';
        a_i=a_i*b_i+c_i;
        string s;
        while(a_i>9){
            s.append(1,a_i%10+'0');
            a_i=a_i/10;
        }
        s.append(1,a_i%10+'0');
        return s;
    }
    //"s......." x a
    //字符串中高位在后面
    string strXchar(const string &s,const char &a){
    	if(a=='0')
    		return "0";
    	char step='0';
    	string tmp;
    	string line(s.size()+1,'0');
    	int pos=line.size()-1;
    	for(int i=s.size()-1;i>=0;i--){
    		//s中的元素轮流与a相乘
    		tmp=charXchar(s[i],a,step);
    		if(tmp.size()>1){
    			step=tmp[1];
    		}else{
    			step='0';
    		}
    		line[pos]=tmp[0];
    		pos--;
    	}
    	if(step!='0')
    		line[pos]=step;
    	if(line[0]=='0'){
    		string true_ans(line.size()-1,'0');
    		for(int i=1;i<line.size();i++)
    			true_ans[i-1]=line[i];
    		return true_ans;	
    	}
    	return line;
    }
    //a+b+c
    string add2char(const char &a,const char &b,const char &c){
    	int a_i=a-'0';
        int b_i=b-'0';
        int c_i=c-'0';
        a_i=a_i+b_i+c_i;
        string s;
        while(a_i>9){
            s.append(1,a_i%10+'0');
            a_i=a_i/10;
        }
        s.append(1,a_i%10+'0');
        return s;
    }
    //"s1..."+"s2..."
    string add2str(const string &s1,const string &s2,int offset){
    	if(s1.size()==1 && s1[0]=='0')
    		return s2;
    	int s1_i=s1.size()-1-offset;
    	int s2_i=s2.size()-1;
    	string ans(s1_i>(s2_i+offset)?s1_i+2:s2_i+2+offset,'0');
    	string tmp;
    	char step='0';
    	int pos=ans.size()-1;
    	//从最后一个开始复制
    	int cur=s1.size()-1;
    	for(int j=0;j<offset;j++){
    		if(cur-j>=0)
    			ans[pos]=s1[cur-j];
    		else
    			ans[pos]='0';
    		pos--;
    	}
    	while(s1_i>=0 && s2_i>=0){
    		tmp=add2char(s1[s1_i],s2[s2_i],step);
    		if(tmp.size()>1)
    			step=tmp[1];
    		else
    			step='0';
    		ans[pos]=tmp[0];
    		pos--;
    		s1_i--;
    		s2_i--;
    	}
    	if(step!='0'){
			while(s1_i>=0){
				tmp=add2char(s1[s1_i],'0',step);
				if(tmp.size()>1)
					step=tmp[1];
				else
					step='0';
				ans[pos]=tmp[0];
    			pos--;
				s1_i--;
			}
			while(s2_i>=0){
				tmp=add2char('0',s2[s2_i],step);
				if(tmp.size()>1)
					step=tmp[1];
				else
					step='0';
				ans[pos]=tmp[0];
    			pos--;
				s2_i--;
			}
    	}else{
    		while(s1_i>=0){
				ans[pos]=s1[s1_i];
    			pos--;
				s1_i--;
			}
			while(s2_i>=0){
				ans[pos]=s2[s2_i];
    			pos--;
				s2_i--;
			}
    	}
    	if(step!='0'){
    		ans[pos]=step;
    		pos--;
    	}
    	
    	if(ans[0]=='0'){
    		string true_ans(ans.size()-1,'0');
    		for(int i=1;i<ans.size();i++)
    			true_ans[i-1]=ans[i];
    		return true_ans;	
    	}
    	return ans;
    }
    string printit(const string s){
    	for(int i=s.size()-1;i>=0;i--){
    		cout<<s[i];
    	}
    	cout<<endl;
    }
};
int main(){
	Solution s;
	string str;
	string str1;
	char ch;
	cin>>str;
	cin>>str1;
	cout<<s.multiply(str,str1)<<endl;
}
