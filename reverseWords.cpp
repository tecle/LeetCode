#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    class Pos{
        public :
            //a b:12
           int left;//first blank
           int right;//first char not blank
           Pos():left(0),right(0){} 
    };
    void reverseWords(string &s) {
        int s_len=s.size(),i=0;
        if(s_len==0)
            return;
        vector<Pos> rcd;
        Pos pos;
        //find start char and end char that not blank
        int start=0,end=s_len-1;
        while(start<s_len && s[start]==' ')
            start++;
        while(end>=0 && s[end]==' ')
            end--;
        
        //if str only have blank
        if(start>end){
            s="";
            return;
        }
        //searching for blank's position
        i=start;
        while(i<end){
            if(s[i]==' '){
                pos.left=i;
                while(i<s_len && s[i]==' ')
                    i++;
                pos.right=i;
                rcd.push_back(pos);
            }
            i++;
        }
        string newS="";
        int rcd_len=rcd.size();
        int pre=s_len-1;
        //there is no blank
        if(rcd_len==0){
            s=s.substr(start,end-start+1);
            return;
        }
        //build str
        for(i=rcd_len-1;i>=0;i--){
        	cout<<pre<<","<<rcd[i].left<<","<<rcd[i].right<<endl;
            newS+=s.substr(rcd[i].right,pre-rcd[i].right+1);
            pre=rcd[i].left-1;
            newS.append(1,' ');
        }
        newS+=s.substr(start,pre-start+1);
        s=newS;
    }
};
int main(){
	Solution ss;
	vector<string> vs={" a  c   d   "};
	for(auto & s:vs){
		cout<<s<<"|"<<endl;
		ss.reverseWords(s);
		cout<<s<<"|"<<endl;
	}
	vs.push_back(NULL);

	int i=-123123;
	char * as;
	itoa(i,as,10);
	string intStr(as);
	cout<<intStr<<endl;
}
