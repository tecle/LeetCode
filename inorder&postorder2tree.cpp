#include "myhead.h"
/**
 * Definition for binary tree*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size()==0)
            return NULL;
        return bt(inorder,postorder,0,postorder.size()-1,0,postorder.size()-1);
    }
    TreeNode *bt(vector<int> &vi, vector<int> &vp,int head ,int tail,int start,int end){
        //cout<<head<<","<<tail<<","<<start<<","<<end<<endl;
        if(head>tail)
            return NULL;
        TreeNode *node=new TreeNode(vp[end]);
        if(head==tail)
            return node;
        int mid=-1;
        for(int i=head;i<=tail;i++)
            if(vi[i]==vp[end]){
                mid=i;
                break;
            }
        TreeNode *left=bt(vi,vp,head,mid-1,start,start+mid-head-1);
        TreeNode *right=bt(vi,vp,mid+1,tail,end+mid-tail,end-1);
        node->left=left;
        node->right=right;
        return node;
    }
};
void travel(TreeNode *root){
	if(root==NULL)
		return;
	
	cout<<root->val<<endl;
	travel(root->left);
	travel(root->right);
}
int main(){
	vector<int> v1={1,2};
	vector<int> v2={2,1};
	Solution s;
	TreeNode* t=s.buildTree(v1,v2);
	travel(t);
}
