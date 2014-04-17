#include "myhead.h"

/**
 * Definition for binary tree
*/ struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
typedef TreeNode * TN;
class Solution {
public:
    bool first;
    vector<TreeNode*> rcd;
    void recoverTree(TreeNode *root) {
        first=true;
        if(!root)
            return;
            
        TreeNode * pre=NULL;
        find(root,&pre);
        int tmp=rcd[0]->val;
        rcd[0]->val=rcd[1]->val;
        rcd[1]->val=tmp;
        
    }
    void find(TreeNode *now,TreeNode **pre){
        if(now->left)
            find(now->left,&(*pre));
        
        if((*pre) && now->val < (*pre)->val){
            
            if(first){
            	cout<<(*pre)->val<<","<<now->val<<endl;
                rcd.push_back(*pre);    
                rcd.push_back(now);
                first=false;
            }else{
            	cout<<now->val<<endl;
                rcd.pop_back();
                rcd.push_back(now);
            }
        }
        *pre = now;
        
        if(now->right)
            find(now->right,&(*pre));
    }
};

int main(){
	TN root=new TreeNode(2);
	root->left=new TreeNode(3);
	root->right=new TreeNode(1);
	Solution s;
	s.recoverTree(root);

}


