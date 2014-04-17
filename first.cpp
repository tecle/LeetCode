#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
using namespace std;

/**
 * Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *root;
    void insert(int num){
    	cout<<"insert :"<<num<<endl;
        TreeNode *node=root;
        TreeNode *preNode=NULL;
        bool isLeft=true;
        while(node!=NULL){
            preNode=node;
            if(node->val > num){//if current node's value is bigger than this number,put the number into left tree
                node=node->left;
                isLeft=true;
            }else{
                node=node->right;//else put the number into right tree
                isLeft=false;
            }
        }
        //by checking isLeft ,we can detemine where new number should be put
        if(isLeft){
            preNode->left=(TreeNode*) malloc(sizeof(TreeNode));
            preNode->left->val=num;
        }
        else{
            preNode->right=(TreeNode*) malloc(sizeof(TreeNode));
            preNode->right->val=num;
        }
        //put this number to new tree node
        
    }
    void selectNum(vector<int> &num,int start,int end){
    	cout<<"left:"<<start<<"right"<<end<<endl;
        if(start>end)
            return;
        insert(num[(start+end)/2]);
        selectNum(num,start,(start+end)/2-1);
        selectNum(num,(start+end)/2+1,end);
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        root=(TreeNode*) malloc(sizeof(TreeNode));
        root->val=INT_MIN;
        
        selectNum(num,0,num.size()-1);
        return root->right;
    }
    
    
};
void printTree(TreeNode *t){
	if(t==NULL)
		return;
	cout<<t->val<<endl;
	printTree(t->left);
	printTree(t->right);
}
int main(){
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	TreeNode * root=s.sortedArrayToBST(v);
	printTree(root);
}
