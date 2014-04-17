#include<iostream>
#include<stdlib.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//出错原因是没想到begin和end可以相等
class Solution {
public:
    TreeNode *thead;
    TreeNode *sortedListToBST(ListNode *head) {
        thead=NULL;
        if(head==NULL)
            return thead;
        build(head,NULL);
        return thead;
    }
    void insert(int v){
    	cout<<"insert:"<<v<<endl;
        if(thead==NULL){
            thead=(TreeNode*) malloc(sizeof(TreeNode));
            thead->left=NULL;
            thead->right=NULL;
            thead->val=v;
            return ;
        }
        TreeNode *now=thead;
        TreeNode *pre;
        bool isLeft=true;
        while(now){
    
            pre=now;
            //if v is bigger,go to right node
            if(now->val<=v){
                now=now->right;
                isLeft=false;
            }
            else{
                isLeft=true;
                now=now->left;
            }
            
        }
        now=(TreeNode*) malloc(sizeof(TreeNode));
        now->left=NULL;
        now->right=NULL;
        now->val=v;
        if(isLeft){
            pre->left=now;
        }else
            pre->right=now;
        
    }
    void build(ListNode* begin, ListNode *end){
        if(begin==NULL)
            return;
        cout<<"begin:"<<begin<<",end:"<<end<<endl;
        ListNode* quick=begin;
        ListNode* slow=begin;
        if(begin->next==end ){
            insert(begin->val);
            return;
        }
        if(begin==end)
        	return;
        while(true){
        	cout<<"slow:"<<slow<<",quick:"<<quick<<",end:"<<end<<endl;
            slow=slow->next;
            quick=quick->next;
            
            if(quick->next==end ){
            	cout<<"1"<<endl;
                insert(slow->val);
                build(begin,slow);
                build(slow->next,end);
                return;
            }
            if(quick->next->next==end){
            	cout<<"2"<<endl;
            	insert(slow->val);
                build(begin,slow);
                build(slow->next,end);
                return;
            }
            quick=quick->next;
        }
    }
};
int main(){
	ListNode *head=NULL;
	ListNode *node;
	ListNode *pre;
	int i;
	while(cin>>i){
		
		node=(ListNode *)malloc(sizeof(ListNode));
		node->next=NULL;
		node->val=i;
		cout<<node<<endl;
		if(head==NULL){
			head=node;
			pre=head;
		}
		if(pre!=NULL)
			pre->next=node;
		pre=node;
	}
	Solution s;
	TreeNode *ans=s.sortedListToBST(head);
}
