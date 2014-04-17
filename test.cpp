#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;

/**
 Definition for undirected graph.
**/
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
typedef UndirectedGraphNode * ug;
class Solution {
public:
    map<int,int> flag;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
            return NULL;
        f(node);
        g(node);
        UndirectedGraphNode *first=(node->neighbors).back();
        h(node);
        return first;
    }
    //第一轮构造，创建等价节点
    void f(UndirectedGraphNode *node){
        //not been travel
        if(flag[node->label]!=1){
            //复制该点
            UndirectedGraphNode *newNode=(UndirectedGraphNode *) malloc(sizeof(UndirectedGraphNode));
            newNode->label=node->label;
            //标记为已经访问了
            flag[node->label]=1;
            
            int nsize=(node->neighbors).size();
            for(int i=0;i<nsize;i++)
                f((node->neighbors)[i]);
            (node->neighbors).push_back(newNode);
        }
        
    }
    //第二轮构造，构造出拷贝
    void g(UndirectedGraphNode *node){
        //该点已经访问过了
        if(flag[node->label]==2)
            return;
        flag[node->label]=2;
        int i;
        UndirectedGraphNode* tmp = (node->neighbors).back();
        
        int nbsz=(node->neighbors).size();
        for(i=0;i<nbsz-1;i++)
            (tmp->neighbors).push_back( (((node->neighbors)[i])->neighbors).back() );
        for(i=0;i<nbsz-1;i++)
            g( (node->neighbors)[i] );
    }
    //第三轮，恢复原始
    void h(UndirectedGraphNode *node){
        if(flag[node->label]==3)
            return;
        flag[node->label]=3;
        //cout<<(node->neighbors).size()<<endl;
        (node->neighbors).pop_back();
        int nbsz=(node->neighbors).size();
        int i;
        for(i=0;i<nbsz;i++)
            h( (node->neighbors)[i] );
    }
    
};
ug buildNode(){
	return (ug)malloc(sizeof(UndirectedGraphNode));
}
map<int ,int> flag;
void printG(ug g){
	if(flag[g->label]==1)
		return;
	flag[g->label]=1;
	cout<<g->label<<"[ ";
	int i;
	for(i=0;i<(g->neighbors).size();i++)
		cout<<(g->neighbors)[i]->label<<" ";
	cout<<"]"<<endl;
	for(i=0;i<(g->neighbors).size();i++)
		printG((g->neighbors)[i]);
}
int main(){
	vector<int> v(12);
	cout<<v[2]<<endl;
	//cout<<(head->neighbors)[0]->label<<endl;
	return 1;
}
