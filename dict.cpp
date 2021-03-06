#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    class Node{
    	public:
    		Node* node[26];
    		bool isEnd;
    	public:
    		Node (string s):isEnd(false){
    			for(int i=0;i<26;i++){
    				node[i]=NULL;
    			}
    		}
    		void addElement(string s){
    			Node * cur= this;
    			int j,size;
    			size=s.size();
    			for(j=0;j<size;j++){
    				
    				if(cur->node[s[j]-'a']==NULL){
    
    					cur->node[s[j]-'a']=(Node *)malloc(sizeof(Node));
    				}
    				cur=cur->node[s[j]-'a'];
    			}
    			cur->isEnd=true;
    		}
    		
    };
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        if(strs.size()==0)
            return ans;
        Node *root=(Node *)malloc(sizeof(Node));
        int i,j,sz;
        sz=strs.size();
        //构造字典树
        for(i=0;i<sz;i++){
            root->addElement(strs[i]);
        }
        Node *cur;
        for(i=0;i<sz;i++){
            cur=root;
            for(j=strs[i].size()-1;j>=0;j--){
                //当前字符在树中存在
                if(cur->node[strs[i][j]-'a'])
                    cur=cur->node[strs[i][j]-'a'];
                else
                    break;
            }
            if(j<0 && cur && cur->isEnd)
                ans.push_back(strs[i]);
        }
        return ans;
    }
};
int main(){
	string a[15]={"ute","fey","toe","lob","pet","ted","old","bye","car","peg","maw","toe","has","dot","tam"};
	vector<string> v;
	for(int i=0;i<15;i++)
		v.push_back(a[i]);
	Solution s;
	v=s.anagrams(v);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	return 0;
}

