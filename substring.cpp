#include "myhead.h"
class Solution {
public:
	class TrieTree{
        public:
        TrieTree * tt[26];
        int index;
        TrieTree():index(-1){
            for(int i=0;i<25;i++)
                tt[i]=NULL;
        }
        void addEle(string &s,int &turn){
            TrieTree *now = this;
            for(int i=0;i<s.size();i++)
            {
                if(now->tt[ s[i]-'a' ] == NULL)
                    now->tt[ s[i]-'a' ]=new TrieTree;
                now=now->tt[ s[i]-'a' ];
            }
            now->index=turn;
        }
    };
    int len,slen,wlen;
    TrieTree *root;
    vector<int> findSubstring(string s, vector<string> &L) {
        vector<int> ans;
        root=new TrieTree;
        int i=0;
        len=L.size();
        slen=s.size();
        wlen=L[0].size();
        for(i=0;i<len;i++){
            root->addEle(L[i],i);
            //cout<<i<<endl;
            }
            
        //construct trie
        int tmp;
        i=0;
        while(i<slen){

            tmp = judge(s,i);
         
            if( tmp < 0){
                i++;
                continue;
            }
            else{ 
                ans.push_back(i);
                i+=tmp;
            }
            
        }
        return ans;
    }
    int judge(string &s,int start){
        map<int,int> flag;

        int tmp,cnt=0,i=start;
        while(cnt<len){
        	
        	if(i>=slen)
        		break;
            tmp=isInTrie(s,i);
            if(tmp<0)
                return -1;
            if(flag[tmp]==0)
                flag[tmp]=1;
            else
                return -1;
            cnt++;
            i+=wlen;
        }
        for(int j=0;j<len;j++)
            if(flag[j]!=1)
                return -1;
        
        return len*wlen;
    }
    int isInTrie(string &s,int begin){
        int i=begin;
        TrieTree *now=root;
        while(now != NULL && i < slen){
            if(now->tt[ s[i]-'a' ]!=NULL)
                now=now->tt[ s[i]-'a' ];
            else
                return -1;
                
            if(now->index>=0){

                return now->index;
             }
            
            i++;
        }
        
        return -1;
    }
    
};
int main(){
	vector<string> strs={"aaa","bbb"};
	string str="aaaaaaaa";
	Solution s;
	vector<int> v=s.findSubstring(str,strs);
	for(auto &ii:v)
		cout<<ii<<endl;
}
