#include "myhead.h"

class Solution {
public:
    string minWindow(string S, string T) {
        int i,j,slen=S.size(),tlen=T.size();
        unordered_set<char> flag;
        unordered_set<char> tspace;
        for(i=0;i<tlen;i++)
        	tspace.insert(T[i]);
        
        int v=3,head=0,tail=0;
        int total=0,cur;
        int min_head=-1,min_tail=-1,min=INT_MAX;
        i=0;
        queue<int> index;
        
        for(i=0;i<slen;i++){
        	//如果该元素不在T中，下一个
        	if(tspace.count( S[i] ) < 1)
        		continue;
        	//找到一个重复元素,重置head的位置
        	
        	if(flag.count( S[i] ) > 0){
        		while(!index.empty()){
        			cur=index.front();
        			//弹出的元素标记值都减1
        			if(S[cur] != S[i]){
        				index.pop();
        				//已找到的元素中删除它

        				flag.erase(S[cur]);
        				total--;
        			}else{
        				//最后一个元素是重复的，不用减少
        				index.pop();

        				index.push(i);
        				break;
        			}
        			
        		}
        		continue;
        	}
        	
        	//这个元素属于T，目前没有出现过，则进行记录
        	total++;
        	flag.insert( S[i] );
        	//将索引放入队列
        	index.push(i);
        	//找到一个window,保存下来
        	if(total==tlen){
        		cur=-index.front()+i;
        		if(cur<min){
        			min_head=index.front();
        			min_tail=i;
        			min=cur;
        		}
        		//重新定位第一个头,
        		if(!index.empty()){
        			cur=index.front();
        			index.pop();
        			flag.erase(S[cur]);
        			total--;
        		}
        	}	
        }
        if(min_head<0)
        	return "";
        return S.substr(min_head,min_tail-min_head+1);
    }
};

int main(){
	string str1="ADOBECODEBANC";
	string str2="ABC";
	Solution s;
	cout<<s.minWindow(str1,str2)<<endl;
}
