#include "myhead.h"

/**
 * Definition for binary tree
 */struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root==NULL)
            return;
        f(root);
    }
    TreeNode *f(TreeNode *node){
        if(node->left==NULL && node->right==NULL)
            return node;
        TreeNode *tmp;
        if(node->left!=NULL && node->right!=NULL){
            tmp=node->right;
            node->right=node->left;
            //flat left nodes and point the last node's right space to right node 
            f(node->left)->right=tmp;
            node->left=NULL;//set left child to null
            tmp=f(tmp);
            tmp->right=NULL;
            return tmp;
        }
        if(node->left!=NULL){
            node->right=node->left;
            node->left=NULL;//set left child to null
            tmp=f(node->right);
            tmp->right=NULL;
            return tmp;
        }
        if(node->right!=NULL){
            tmp=f(node->right);
            tmp->right=NULL;
            return tmp;
            
        }
            
    }
};

int main(){
	TreeNode *t=new TreeNode(1);
	t->right=new TreeNode(2);
	t->left=new TreeNode(3);
	t->left->left=new TreeNode(4);
	t->left->right=new TreeNode(5);
	Solution s;
	s.flatten(t);
	while(t!=NULL){
		cout<<t->left<<","<<t->val<<endl;
		t=t->right;
	}
}
