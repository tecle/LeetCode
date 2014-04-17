#include "myhead.h"
class Solution {
public:
    map<string,int> rcd;
    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        
        //used to save string's level
        map<string,int> m;
        m[start]=0;
        
        //save path
        vector<vector<string> > path;
        //used it to bfs
        queue< pair<string,vector<vector<string> > > >q;
        //put start to first node
        path.push_back(vector<string>(1,start));
        q.push(pair<string,vector<vector<string> > >(start,path));
        
        //save all strings in a level
        unordered_set<string> level;
        unordered_set<string> :: iterator itr;
        //save current level
        int cur=-1;
        
        
        bool hasFoundEnd=false;
        int i,j,wlen=start.size();
        char ch;
        pair<string,vector<vector<string> > > now;
        //main
        while(!q.empty()){
            
            now=q.front();
            q.pop();
            
            //when we can judge where this node is last node in this level ?
            if(cur!=m[now.first]){
                cur=m[now.first];
                
                //delete all nodes of pre level
                itr=level.begin();
                while(itr!=level.end())
                    dict.erase(*itr);
                level.clear();
            }
            //this node is last node
            if(now.first == end){
                for(auto &v:now.second){
                    ans.push_back(v);
                }
                hasFoundEnd=true;
                continue;
            }
            
            if(hasFoundEnd)
                continue;
                
            for(i=0;i<wlen;i++){
                string word(now.first);
                ch=word[i];
                for(j=0;j<26;j++){
                	if( j+'a' == ch )
                		continue;               
                    word[i]=j+'a';
                    //find a node
                    if( dict.count(word)>0 ){
                        //generate new path
                        path.clear();
                        for(auto &v:now.second){
                            v.push_back(word);
                            path.push_back(v);
                        }
                        //put node into queue with it's path
                        q.push(pair<string,vector<vector<string> > >(word,path));
                        
                        //record this level
                        m[word]=m[now.first]+1;
                        
                        //insert this node map
                        level.insert(word);
                        
                        //if it is last string in current level,we should delete all string in space
                        /*if(lastNodeInCurLevel){
                            itr=level.begin();
                            while(itr!=level.end())
                                dict.erase(*itr);
                            level.clear();
                            lastNodeInCurLevel=false;
                        }*/
                        
                    }
                   
                }
                word[i]=ch;
            }
            
        }
        return ans;
        
    }
};

int main(){
	Solution s;
	string start,end,tmp;
	unordered_set<string> dict;
	vector<vector<string>> vt;
	while(1){
		dict.clear();
		cout<<"start:";
		cin>>start;
		cout<<"end:";
		cin>>end;
		cout<<"dict:"<<endl;
		cin>>tmp;
		while( tmp != "end" ){
			dict.insert(tmp);
			cin>>tmp;
		}
		cout<<"dealing..."<<endl;
		vt=s.findLadders(start,end,dict);
		for(auto &vt0:vt)
			for(auto &vt1:vt0)
				cout<<vt1<<" ";
		cout<<endl;
	}

}
