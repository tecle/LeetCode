#include "myhead.h"

class Solution {
public:

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end)
            return 0;
        queue< pair<string,int> > q;
        //dict.insert(start);
        dict.insert(end);
        q.push( pair<string,int>(start,0));
        
        pair<string,int> tmp;
        
        int i,j,wlen=start.size();
        char ch;
        while( ! q.empty() ){
        
        	
            //pop out an element
            tmp=q.front();
            //delete this element
            q.pop();
            
            //cout<<"pop:"<<tmp.first<<endl;
            //reach the end!
            if(tmp.first==end)
                return tmp.second+1;
            
            //find all elements that tmp can reach
            for(i=0;i<wlen;i++){
            	string word(tmp.first);
            	for(j=0;j<26;j++){
            		ch=word[i];
            		word[i]=j+'a';
            		if( dict.count(word) > 0 ){
            			//cout<<word<<endl;
            			q.push( pair<string,int>(word,tmp.second+1) );
            			//delete element
            			dict.erase(word);
            		}
            		word[i]=ch;
            	}
            }
        }
        return 0;
    }
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

int main(){
	Solution s;
	unordered_set<string> dict;
	vector<string> strs={"hot","dot","dog","lot","log"};
	for(auto &str:strs)
		dict.insert(str);
	cout<<s.ladderLength("hit","cog",dict)<<endl;
	
}
